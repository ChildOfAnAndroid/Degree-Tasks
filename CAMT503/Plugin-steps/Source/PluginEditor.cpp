/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PluginstepsAudioProcessorEditor::PluginstepsAudioProcessorEditor (PluginstepsAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    // Step 14: Add and make visibe the keyboard component
    addAndMakeVisible(&keyboardComponent);
    
    // Step 15: Add a listener to the keyboard state
    keyboardState.addListener (&audioProcessor.getMidiMessageCollector());
    // You will find an error. getMidiMessageCollector needs to be defined. Go to PluginProcessor.h

}

PluginstepsAudioProcessorEditor::~PluginstepsAudioProcessorEditor()
{
    // Step 17: Remove the keyboardState listener.
    keyboardState.removeListener (&audioProcessor.getMidiMessageCollector());
}

//==============================================================================
void PluginstepsAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void PluginstepsAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    // Step 18: Add dimensions of keyboardComponent
    keyboardComponent.setBounds(8, 96, getWidth() - 16, 64);
    
    // Step 19: Run the stand-alone program! You will be able to see an on-screen keyboard.
    
    // Stp 20: Build the VST plugin and test on Reaper. Remember to restart Reaper.
    
    // Task: Create two rotary sliders or knobs to adjust attack and delay of the sound.
}
