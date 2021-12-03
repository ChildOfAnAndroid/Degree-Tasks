/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SoundSynthAudioProcessor::SoundSynthAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
    // Add voices and sound to the synth object.
    for (auto i = 0; i < 5; i++)
    {
        synth.addVoice(new SineWaveVoice());
    }
    
    synth.addSound(new SineWaveSound());
}

SoundSynthAudioProcessor::~SoundSynthAudioProcessor()
{
}

//==============================================================================
const juce::String SoundSynthAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool SoundSynthAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool SoundSynthAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool SoundSynthAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double SoundSynthAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int SoundSynthAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int SoundSynthAudioProcessor::getCurrentProgram()
{
    return 0;
}

void SoundSynthAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String SoundSynthAudioProcessor::getProgramName (int index)
{
    return {};
}

void SoundSynthAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void SoundSynthAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    synth.setCurrentPlaybackSampleRate(sampleRate);
}

void SoundSynthAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool SoundSynthAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void SoundSynthAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);

        // ..do something to the data...
    }
    
    auto audioBusBuffer = getBusBuffer(buffer, false, 0);
    
    synth.renderNextBlock(audioBusBuffer, midiMessages, 0, audioBusBuffer.getNumSamples());
    
}

//==============================================================================
bool SoundSynthAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* SoundSynthAudioProcessor::createEditor()
{
    return new SoundSynthAudioProcessorEditor (*this);
}

//==============================================================================
void SoundSynthAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void SoundSynthAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SoundSynthAudioProcessor();
}


bool SineWaveSound::appliesToNote (int midiNoteNumber)
{
    return true;
}
bool SineWaveSound::appliesToChannel (int midiChannel)
{
    return true;
}

SineWaveVoice::SineWaveVoice() : currentAngle(0.0), angleDelta(0.0), level(0.0), tailOff(0.0), pitchBendInterval(12.0)
{
    
}


bool SineWaveVoice::canPlaySound (juce::SynthesiserSound* sound)
{
    return dynamic_cast<SineWaveSound*>(sound) != nullptr;
}

void SineWaveVoice::startNote (int midiNoteNumber, float velocity, juce::SynthesiserSound *sound, int currentPitchWheelPosition)

{
    currentAngle = 0.0;
    level = velocity * 0.25;
    tailOff = 0.0;
    
    auto cyclesPerSecond = juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber);
    auto cyclesPerSample = cyclesPerSecond / getSampleRate();
    
    angleDelta = cyclesPerSample * 2.0 * juce::MathConstants<double>::pi;
}

void SineWaveVoice::stopNote (float velocity, bool allowTailOff)
{
    if (allowTailOff)
    {
        if (tailOff == 0.0)
        {
            tailOff = 1.0;
        }
    }
    
    else
    {
        clearCurrentNote();
        angleDelta = 0.0;
    }
}

void SineWaveVoice::pitchWheelMoved (int newPitchWheelValue)
{
    
    int maxValue = 16383;
    int minValue = 0;
    int meanValue = 8192;
    
    int note = getCurrentlyPlayingNote();
    
    auto cyclesPerSecond = juce::MidiMessage::getMidiNoteInHertz(note);
    
    if (newPitchWheelValue < 8192)
    {
        auto lowFreq = juce::MidiMessage::getMidiNoteInHertz(note - pitchBendInterval);
        cyclesPerSecond = juce::jmap((float)newPitchWheelValue, (float)minValue, (float)meanValue, (float)lowFreq, (float)cyclesPerSecond);
    }
    
    else if (newPitchWheelValue > 8192)
    {
        auto highFreq = juce::MidiMessage::getMidiNoteInHertz(note + pitchBendInterval);
        cyclesPerSecond = juce::jmap((float)newPitchWheelValue, (float)meanValue, (float)maxValue, (float)cyclesPerSecond, (float)highFreq);
    }
    
    auto cyclesPerSample = cyclesPerSecond / getSampleRate();
    
    angleDelta = cyclesPerSample * 2.0 * juce::MathConstants<double>::pi;
    
    juce::Logger::writeToLog("Pitch Wheel Value: " + std::to_string(newPitchWheelValue));
    
    // HIGHEST VALUE: 16383
    // LOWEST VALUE: 0
    // MID VALUE: 8192
    
}

void SineWaveVoice::controllerMoved (int controllerNumber, int newControllerValue)
{
    
}

void SineWaveVoice::renderNextBlock (juce::AudioBuffer< float > &outputBuffer, int startSample, int numSamples)
{
    if (angleDelta != 0.0)
    {
        if (tailOff > 0.0)
        {
            while (--numSamples >= 0)
            {
                auto currentSample = (float)(sign(std::sin(currentAngle) + std::sin(1.01*currentAngle) + std::sin(0.99*currentAngle)) * tailOff * level);
                
                for (auto i = outputBuffer.getNumChannels();--i >=0;)
                {
                    outputBuffer.addSample(i, startSample, currentSample);
                }
                
                currentAngle += angleDelta;
                ++startSample;
                
                tailOff = tailOff * 0.99;
                
                if (tailOff <= 0.005)
                {
                    clearCurrentNote();
                    angleDelta = 0.0;
                    break;
                }
            }
        }
        
        else
        {
            while (--numSamples >= 0)
            {
                auto currentSample = (float)((std::sin(currentAngle) + std::sin(1.01*currentAngle) + std::sin(0.99*currentAngle)) * level);
                
                for (auto i = outputBuffer.getNumChannels();--i >=0;)
                {
                    outputBuffer.addSample(i, startSample, currentSample);
                }
                
                currentAngle += angleDelta;
                ++startSample;
            }
        }
    }
}
