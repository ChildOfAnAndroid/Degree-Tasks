#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent() //this is the CONSTRUCTOR (has same name as file)
    : harmoniseButton("Harmonise"), isHarmonyEnabled(false) //Initialising variables
{
    
    // Make sure you set the size of the component after
    // you add any child components.
    setSize (800, 600);

    // Some platforms require permissions to open input channels so request that here
    if (juce::RuntimePermissions::isRequired (juce::RuntimePermissions::recordAudio)
        && ! juce::RuntimePermissions::isGranted (juce::RuntimePermissions::recordAudio))
    {
        juce::RuntimePermissions::request (juce::RuntimePermissions::recordAudio,
                                           [&] (bool granted) { setAudioChannels (granted ? 2 : 0, 2); });
    }
    else
    {
        // Specify the number of input and output channels that we want to open
        setAudioChannels (2, 2);
    }
    
    addAndMakeVisible(&keyboardComponent);
    addAndMakeVisible(&harmoniseButton);
    
    harmoniseButton.onClick = [this] { updateToggleState (&harmoniseButton, "Harmonise");}; //event handler
    
    formatManager.registerBasicFormats();
    
    synth.addVoice(new juce::SamplerVoice());
    
    juce::File file("/Users/charis/Documents/GitHub/Degree-Tasks/CAMT503/Week 5/KeyboardSynthesiser/Sound Samples/c-guitar.wav"); //CHANGE DEPENDING ON WHAT COMPUTER YOU ARE USING
    juce::FileInputStream inputStream(file);
    
    std::unique_ptr<juce::AudioFormatReader> audioReader(formatManager.createReaderFor(file));
    
    juce::BigInteger allNotes;
    allNotes.setRange(0, 128, true);
    
    synth.clearSounds();
    synth.addSound(new juce::SamplerSound("Cello Sound",
                                          *audioReader,
                                          allNotes,
                                          74, //Root MIDI Note
                                          0.1, //Attack Time
                                          0.1, //Release Time
                                          10.0 //Maximum Sample Length
                                          ));
    
}

MainComponent::~MainComponent()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    // This function will be called when the audio device is started, or when
    // its settings (i.e. sample rate, block size, etc) are changed.

    // You can use this function to initialise any resources you might need,
    // but be careful - it will be called on the audio thread, not the GUI thread.

    // For more details, see the help for AudioProcessor::prepareToPlay()
    
    midiCollector.reset(sampleRate);
    
    synth.setCurrentPlaybackSampleRate(sampleRate);
    
}

void MainComponent::getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill)
{
    // Your audio-processing code goes here!

    // For more details, see the help for AudioProcessor::getNextAudioBlock()

    // Right now we are not producing any data, in which case we need to clear the buffer
    // (to prevent the output of random noise)
    bufferToFill.clearActiveBufferRegion();
    
    juce::MidiBuffer incomingMidi;
    midiCollector.removeNextBlockOfMessages(incomingMidi, bufferToFill.numSamples);
    
    keyboardState.processNextMidiBuffer (incomingMidi, 0, bufferToFill.numSamples, true);
    
    for(auto metadata : incomingMidi) //this prints into the terminal
        if (metadata.numBytes == 3)
            juce::Logger::writeToLog(metadata.getMessage().getDescription());
    
    synth.renderNextBlock (*bufferToFill.buffer, incomingMidi, 0, bufferToFill.numSamples);
    
}

void MainComponent::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    // For more details, see the help for AudioProcessor::releaseResources()
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    // You can add your drawing code here!
}

void MainComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    
    keyboardComponent.setBounds(8, 96, getWidth() - 16, 64);
    harmoniseButton.setBounds(8, 270, getWidth() / 6, 20);
    
}

void MainComponent::updateToggleState(juce::Button* button, juce::String name) //defining custom function from the .h file
{
    isHarmonyEnabled = button->getToggleState();
    
    juce::String harmonyString = isHarmonyEnabled ? "ON" : "OFF"; //conditional operator
    juce::Logger::writeToLog("Harmony is " + harmonyString);
}
