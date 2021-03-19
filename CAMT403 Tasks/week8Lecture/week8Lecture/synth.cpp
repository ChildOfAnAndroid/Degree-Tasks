//
//  synth.cpp
//  Week6Lab
//
//  Created by David Moffat on 12/03/2021.
//  Copyright © 2021 DavidMoffat. All rights reserved.
//

#include "synth.hpp"

float interp(float startVal, float endVal, float val)
{
    return startVal + val*(endVal-startVal);
}

void genSinWave(AudioFile<float>& audioBuffer, float sampleRate, float frequency, float amplitude)
{
    for (int sample = 0; sample < audioBuffer.getNumSamplesPerChannel(); sample++)
    {
        audioBuffer.samples[0][sample] += amplitude * sin(2* M_PI * frequency * sample/sampleRate);
    }
}

void genNoise(AudioFile<float>& audioBuffer, float amplitude)
{
    for (int sample = 0; sample < audioBuffer.getNumSamplesPerChannel(); sample++)
    {
        audioBuffer.samples[0][sample] += amplitude*((float) std::rand()/(float) RAND_MAX);
    }
}

void applyEnvelopeAR(AudioFile<float>& audioBuffer, float sampleRate, float attackTime, float releaseTime)
{
    // COMMENTS EXPLAINING HOW IT ALL WORKS
    int attackTimeSample = attackTime * sampleRate;
    int releaseTimeSamples = releaseTime * sampleRate;
    
    for (int sample = 0; sample < audioBuffer.getNumSamplesPerChannel(); sample++)
    {
        if (sample < attackTimeSample) // ATTACK PHASE
        {
            audioBuffer.samples[0][sample] *= interp(0.0, 1.0, (float)sample/ (float) attackTimeSample);
        }
        else if (sample < attackTimeSample+ releaseTimeSamples) // RELEASE PHASE
        {
            audioBuffer.samples[0][sample] *= interp(1.0, 0.0, (float) (sample-attackTimeSample)/ (float) releaseTimeSamples); //APPLY ENVELOPE
        }
        else
        {
            audioBuffer.samples[0][sample] = 0; // ZERO
        }
    }
}

void operator+=(AudioFile<float>& audioBuffer, const AudioFile<float>& audioBuffer2)
{
    for(int sample = 0; sample < audioBuffer.getNumSamplesPerChannel(); sample++)
    {
        audioBuffer.samples[0][sample] += audioBuffer2.samples[0][sample];
    }
}


void lowPassFilter(AudioFile<float>& audioBuffer, float filterCoefficient)
{
    for (int sample = 1; sample < audioBuffer.getNumSamplesPerChannel(); sample++)
    {
        audioBuffer.samples[0][sample] = (filterCoefficient*audioBuffer.samples[0][sample] + (1-filterCoefficient)*audioBuffer.samples[0][sample-1]);
    }
    
}

void highPassFilter(AudioFile<float>& audioBuffer, float filterCoefficient)
{
    float lowFilter;
    for (int t = 1; t < audioBuffer.getNumSamplesPerChannel(); t++)
    {
        lowFilter = (filterCoefficient*audioBuffer.samples[0][t] + (1-filterCoefficient)*audioBuffer.samples[0][t-1]);
        audioBuffer.samples[0][t] = audioBuffer.samples[0][t] - lowFilter;
    }
}


void clearBuffer(AudioFile<float>& audioBuffer)
{
    for (int sample = 0; sample < audioBuffer.getNumSamplesPerChannel(); sample++)
    {
        audioBuffer.samples[0][sample] = 0.0f;
    }
    
}
