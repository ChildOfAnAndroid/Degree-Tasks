/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SoundSynthAudioProcessorEditor::SoundSynthAudioProcessorEditor (SoundSynthAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    chorusWetMix.setSliderStyle(juce::Slider::Rotary);
    chorusWetMix.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&chorusWetMix);
}

SoundSynthAudioProcessorEditor::~SoundSynthAudioProcessorEditor()
{
}

//==============================================================================
void SoundSynthAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    //g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void SoundSynthAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    auto border = 4;
    auto area = getLocalBounds();
    
    auto sliderArea = area.removeFromTop(area.getHeight());
    chorusWetMix.setBounds(sliderArea.removeFromLeft(sliderArea.getWidth()/2).reduced(border));
    
}
