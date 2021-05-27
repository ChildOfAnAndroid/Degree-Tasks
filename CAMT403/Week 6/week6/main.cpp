//
//  GENERATING AUDIO FILES USING MATHEMATICAL WAVEFORMS
//
//  main.cpp
//  week6
//
//  Created by Charis Cat on 10/03/2021.
//

#include <iostream>
#include "AudioFile.h" //Includes the AudioFile.h which allows extra functions
using namespace std;
#include <cmath>

void generateSineWave(AudioFile<float>& audioBuffer, float sampleRate, float frequency, float amplitude) //Passing audio buffer by reference so it can be modified directly
{
    for (int sample = 0; sample < audioBuffer.getNumSamplesPerChannel(); sample++) //Loop through every sample, reading how big the audio buffer is
    {
        audioBuffer.samples[0][sample] = amplitude * sin(2*M_PI * frequency * sample/sampleRate); //Loop through every sample in channel 0 - Generating a sine wave, sin(2*pi * frequency * time in seconds). Amplitude decreases the volume if it is under 1.
    }
}

void generateSquareWave(AudioFile<float>& audioBuffer, int halfPeriod, float frequency, float amplitude, float sampleValue)
{
    for(int sample = 0; sample < audioBuffer.getNumSamplesPerChannel(); sample++) //Loop through every sample, reading how big the audio buffer is
    {
        if((sample % halfPeriod) == 0) //If the position of the sample in time is completely divisible by the number of samples in half a period
        {
            sampleValue = sampleValue*-1; //Switch the value of the sample, which will create a square wave of chosen frequency. *-1 flips between 1 and -1.
        }
        audioBuffer.samples[0][sample] = amplitude * sampleValue;
    }
}

void generateFMSineWave(AudioFile<float>& audioBuffer, float sampleRate, float frequency, float frequency2, float amplitude, float sampleValue)
{
    for(int sample = 0; sample < audioBuffer.getNumSamplesPerChannel(); sample++) //Loop through every sample, reading how big the audio buffer is
    {
        sampleValue = sin(2*M_PI * frequency * sample/sampleRate) * sin(2*M_PI * frequency2 * sample/sampleRate); //two different sine waves multiplied together
        audioBuffer.samples[0][sample] = amplitude * sampleValue; //Volume control using amplitude variable
    }
}

int main(int argc, const char * argv[]) {
    
    float sampleRate = 44100.00; //Number of samples per second
    float numSamples = sampleRate*3; //Creates 2 seconds of audio by multiplying sample rate by 2
    float frequency = 100.0;
    float frequency2 = 600.0;
    float amplitude = 0.1; //To decrease the volume, you want to multiply by something smaller
    int halfPeriod = sampleRate/(2*frequency); //To calculate how long to remain up or down during a square wave
    float sampleValue = 1;
    
    //Audio Buffer Setup
    AudioFile<float> audioBuffer; //Creates a new data type called audio buffer - a list of numbers that tell a speaker how/where to move to recreate a sound
    audioBuffer.setSampleRate(sampleRate); //Sets the sample rate
    audioBuffer.setAudioBufferSize(1, numSamples); //Sets the size of the audio buffer using numSamples variable, and number of channels. Similar to an array
    
    //Putting Sounds into Audio Buffer (pick one, comment out others)
    //generateSineWave(audioBuffer, sampleRate, frequency, amplitude);
    //generateSquareWave(audioBuffer, halfPeriod, frequency, amplitude, sampleValue);
    generateFMSineWave(audioBuffer, sampleRate, frequency, frequency2, amplitude, sampleValue);
    
    audioBuffer.save("SineWave.wav"); //Save the sine wave, will overwrite any previous saves if the name is not saved
    
    return 0;
}
