/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class PluginstepsAudioProcessorEditor  : public juce::AudioProcessorEditor, private juce::Slider::Listener
{
public:
    PluginstepsAudioProcessorEditor (PluginstepsAudioProcessor&);
    ~PluginstepsAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    PluginstepsAudioProcessor& audioProcessor;
    
    // Step 13: Create objects for juce::MidiKeyboardState and juce::MidiKeyboardComponent
    juce::MidiKeyboardState keyboardState;
    juce::MidiKeyboardComponent keyboardComponent{ keyboardState,
        juce::MidiKeyboardComponent::horizontalKeyboard };
    // Go to PluginEditor.cpp
    
    
    // Step 21: Create a juce::Slider called attackDial
    juce::Slider attackDial;
    // Go to the constructor of PluginEditor.cpp
    
    
    // Step 25: Override the sliderValueChanged function
    void sliderValueChanged(juce::Slider *slider) override;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginstepsAudioProcessorEditor)
};
