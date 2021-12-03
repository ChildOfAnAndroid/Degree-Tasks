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
    chorusWetMix.addListener(this);
    chorusWetMix.setRange(0.0, 1.0, 0.005);
    chorusWetMix.setLookAndFeel(&otherLookAndFeel);
}

SoundSynthAudioProcessorEditor::~SoundSynthAudioProcessorEditor()
{
}

//==============================================================================
void SoundSynthAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    
    getLookAndFeel().setColour (juce::Slider::thumbColourId, juce::Colours::rebeccapurple);

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

void SoundSynthAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    if (slider == &chorusWetMix)
    {
        juce::Logger::writeToLog("Chorus Wet Mix: " + std::to_string(slider->getValue()));
        
        audioProcessor.setChorusWetMix(slider->getValue());
    }
}

void OtherLookAndFeel::drawRotarySlider (juce::Graphics& g, int x, int y, int width, int height, float sliderPos, const float rotaryStartAngle, const float rotaryEndAngle, juce::Slider&)
{
    auto radius = (float) juce::jmin (width / 2, height / 2) - 4.0f;
    auto centreX = (float) x + (float) width  * 0.5f;
    auto centreY = (float) y + (float) height * 0.5f;
    auto rx = centreX - radius;
    auto ry = centreY - radius;
    auto rw = radius * 2.0f;
    auto angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
    
    // fill
    g.setColour (juce::Colours::black);
    g.fillEllipse (rx, ry, rw, rw);

    // outline
    g.setColour (juce::Colours::white);
    g.drawEllipse (rx, ry, rw, rw, 10.0f);
    
    juce::Path p;
    auto pointerLength = radius * 0.33f;
    auto pointerThickness = 2.0f;
    p.addRectangle (-pointerThickness * 0.5f, -radius, pointerThickness, pointerLength);
    p.applyTransform (juce::AffineTransform::rotation (angle).translated (centreX, centreY));
    
    // pointer
    g.setColour (juce::Colours::yellow);
    g.fillPath (p);
    
    //SMALL RADIUS
    radius = (float) juce::jmin (width / 20, height / 20) - 4.0f;
    centreX = (float) x + (float) width  * 0.5f;
    centreY = (float) y + (float) height * 0.5f;
    rx = centreX - radius;
    ry = centreY - radius;
    rw = radius * 2.0f;
    
    //center circle
    g.setColour (juce::Colours::white);
    g.fillEllipse (rx, ry, rw, rw);
    
}
