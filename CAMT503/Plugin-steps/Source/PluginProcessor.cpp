/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PluginstepsAudioProcessor::PluginstepsAudioProcessor()
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
    // Step 2: Register basic formats
    formatManager.registerBasicFormats();
    
    // Step 3: Add voices
    for (int i = 0; i < 5; i++)
        synth.addVoice(new juce::SamplerVoice());
    
    // Step 4: Load sounds
    synth.clearSounds();
    juce::File soundSample("D:\\Code\\CAMT503-materials\\Lectures\\Week 5\\Synthesiser\\piano-A3.wav");
    
    std::unique_ptr<juce::AudioFormatReader> audioReader(formatManager.createReaderFor(soundSample));
    juce::BigInteger allNotes;
    allNotes.setRange(0, 128, true);
    synth.addSound(new juce::SamplerSound("Piano sound",
        *audioReader,
        allNotes,
        57,   // root midi note
        0.01,  // attack time
        1.0,  // release time
        10.0  // maximum sample length
    ));
}

PluginstepsAudioProcessor::~PluginstepsAudioProcessor()
{
}

//==============================================================================
const juce::String PluginstepsAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool PluginstepsAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool PluginstepsAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool PluginstepsAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double PluginstepsAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int PluginstepsAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int PluginstepsAudioProcessor::getCurrentProgram()
{
    return 0;
}

void PluginstepsAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String PluginstepsAudioProcessor::getProgramName (int index)
{
    return {};
}

void PluginstepsAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void PluginstepsAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    
    // Step 5: Set the sampling rate of the synthesiser.
    synth.setCurrentPlaybackSampleRate(sampleRate);
    
    // Step 10: Set the sampling rate of the midiMessageCollector
    midiMessageCollector.reset(sampleRate);
}

void PluginstepsAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool PluginstepsAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
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

void PluginstepsAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
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

    
    // Step 11: Remove and process messages in the midiMessageCollector
    midiMessageCollector.removeNextBlockOfMessages(midiMessages, buffer.getNumSamples());
    
    // Step 12: Print the data in the Logger
    for (auto metadata : midiMessages)
    {   juce::Logger::writeToLog(metadata.getMessage().getDescription());
    }
    // Go to PluginEditor.h
    
    
    // Step 6: Create an audioBusBuffer and then render the sound
    auto audioBusBuffer = getBusBuffer(buffer, false, 0);
    
    synth.renderNextBlock(audioBusBuffer, midiMessages, 0, audioBusBuffer.getNumSamples());
    
    
    // Step 7: Run the program!
    
    /* Step 8: Your VST plugin will be stored in /Users/svenkatesh/Library/Audio/Plug-Ins/VST3.
    Check how the plugin works in Reaper. Make sure path to VST plugins includes the above path.
     Go to PluginProcessor.h
     */
    
    
}

//==============================================================================
bool PluginstepsAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* PluginstepsAudioProcessor::createEditor()
{
    return new PluginstepsAudioProcessorEditor (*this);
}

//==============================================================================
void PluginstepsAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void PluginstepsAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new PluginstepsAudioProcessor();
}
