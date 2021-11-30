/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/**
*/
class PluginstepsAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    PluginstepsAudioProcessor();
    ~PluginstepsAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    // Step 16: Define the function getMidiMessageCollector
    juce::MidiMessageCollector& getMidiMessageCollector() noexcept { return midiMessageCollector; }
    // Go back to PluginEditor.cpp

    // Step 28: Create a float called 'attack'
    float attack;
    
    // Step 30: Declare a function called updateSounds
    void updateSounds();
    
private:
    //==============================================================================
    
    // Step 1: Create objects of type juce::AudioFormatManager and juce::Synthesiser
    juce::AudioFormatManager formatManager;
    juce::Synthesiser synth;
    //Go to PluginProcessor.cpp
    
    /* Step 9: Create a juce::MidiMessageCollector object. 
    The midiMessageCollector is for the on-screen keyboard
    */
     juce::MidiMessageCollector midiMessageCollector;
    // Go to PluginProcessor.cpp
    

    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginstepsAudioProcessor)
};
