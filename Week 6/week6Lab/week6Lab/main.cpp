//
//  main.cpp
//  week6Lab
//
//  Created by Charis Cat on 12/03/2021.
//

#include <iostream>
#include "AudioFile.h"

float interp(float startVal, float endVal, float val)
{
    return startVal + val*(endVal-startVal);
}

void genSinWave (AudioFile<float>& audioBuffer, float sampleRate, float frequency, float amplitude)
{
    for(int sample = 0; sample < audioBuffer.getNumSamplesPerChannel(); sample++)
    {
        audioBuffer.samples[0][sample] += amplitude * sin(2*M_PI * frequency * sample/sampleRate); //Sine wave
    }
}

void genNoise (AudioFile<float>& audioBuffer, float amplitude)
{
    for (int sample = 0; sample < audioBuffer.getNumSamplesPerChannel(); sample++)
    {
        audioBuffer.samples[0][sample] += amplitude * ((float) rand()/(float) RAND_MAX); //White Noise, random number between 0 and 1
    }
}

void applyEnvelopeAR(AudioFile<float>& audioBuffer, float sampleRate, float attackTime, float releaseTime)
{
    int attackTimeSample = attackTime*sampleRate;
    int releaseTimeSamples = releaseTime*sampleRate;

    for (int sample = 0; sample < audioBuffer.getNumSamplesPerChannel(); sample++)
    {
        if (sample < attackTimeSample) //Attack Phase
        {
            audioBuffer.samples[0][sample] *= interp(0.0, 1.0, (float)sample/(float)attackTimeSample);
        }
        else if (sample < attackTimeSample + releaseTimeSamples) //Release Phase
        {
            //apply envelope
            audioBuffer.samples[0][sample] *= interp(1.0, 0.0, (float)(sample-attackTimeSample)/(float)releaseTimeSamples);
        }
        else
        {
            //zero
            audioBuffer.samples[0][sample] = 0;
        }
    }
}

void operator+=(AudioFile <float>& audioBuffer, AudioFile<float>& audioBuffer2) //Copys from the first buffer into the second buffer
{
    for(int sample = 0; sample < audioBuffer.getNumSamplesPerChannel(); sample++)
    {
        audioBuffer.samples[0][sample] += audioBuffer2.samples[0][sample];
    }
}

int main(int argc, const char * argv[]) {

    float sampleRate = 44100.0;
    int numSamples = sampleRate*1;
    
    AudioFile<float> audioBuffer;
    audioBuffer.setSampleRate(sampleRate);
    audioBuffer.setAudioBufferSize(1, numSamples);
    
    float frequency = 260.0;
    float amplitude = 0.1;
    
    genSinWave(audioBuffer, sampleRate, frequency, amplitude);
    genSinWave(audioBuffer, sampleRate, frequency/3, amplitude);
    genSinWave(audioBuffer, sampleRate, frequency/6, amplitude);
    genSinWave(audioBuffer, sampleRate, frequency/9, amplitude);
    genSinWave(audioBuffer, sampleRate, frequency/12, amplitude);

    applyEnvelopeAR(audioBuffer, sampleRate, 0.2, 1.2);
    
    
    AudioFile<float> audioBuffer2;
    audioBuffer2.setSampleRate(sampleRate);
    audioBuffer2.setAudioBufferSize(1, numSamples);
    
    genNoise(audioBuffer2, 0.05);
    
    applyEnvelopeAR(audioBuffer2, sampleRate, 0.1, 0.9);

    //addBuffers(audioBuffer, audioBuffer2);
    audioBuffer += audioBuffer2;
    
    audioBuffer.save("SineNoise2Buffer.wav");
    
    std::cout << "Hello, World!\n";
    return 0;
}
