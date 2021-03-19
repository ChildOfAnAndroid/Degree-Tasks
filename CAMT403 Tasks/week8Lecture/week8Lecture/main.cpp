#include <iostream>
#include "synth.hpp"
#include <array>
void makeSnare(AudioFile<float>& audioBuffer)
{
    clearBuffer(audioBuffer);
    genNoise(audioBuffer, 0.1f);
    lowPassFilter(audioBuffer, 0.5f);
    applyEnvelopeAR(audioBuffer, audioBuffer.getSampleRate(), 0.0f, 0.225f);
 }

void makeHat(AudioFile<float>& audioBuffer)
{
    clearBuffer(audioBuffer);
    genNoise(audioBuffer, 0.1f);
    highPassFilter(audioBuffer, 0.1f);
    applyEnvelopeAR(audioBuffer, audioBuffer.getSampleRate(), 0.0f, 0.1f);
}

void makeKick(AudioFile<float>& audioBuffer)
{
    float sampleRate = audioBuffer.getSampleRate();
    clearBuffer(audioBuffer);
    genSinWave(audioBuffer, sampleRate, 55.0f, 0.05f);
    genSinWave(audioBuffer, sampleRate, 65.0f, 0.1f);
    genSinWave(audioBuffer, sampleRate, 70.0f, 0.05f);
    applyEnvelopeAR(audioBuffer, sampleRate, 0.0f, 0.16f);
}


int main() {

    float sampleRate = 44100.0f;
    
    AudioFile<float> kickBuffer;
    kickBuffer.setSampleRate(sampleRate);
    kickBuffer.setAudioBufferSize(1, 2*sampleRate);
    makeKick(kickBuffer);
    
    AudioFile<float> snareBuffer;
    snareBuffer.setSampleRate(sampleRate);
    snareBuffer.setAudioBufferSize(1, 2*sampleRate);
    makeSnare(snareBuffer);
    
    AudioFile<float> hatBuffer;
    hatBuffer.setSampleRate(sampleRate);
    hatBuffer.setAudioBufferSize(1, 2*sampleRate);
    makeHat(hatBuffer);
    
    float BPM = 120.0f;
    int numBar = 16;
    const int beatsInbar = 8;
    
    std::array<bool,beatsInbar> kickTime =   {1,0,0,1,0,0,1,0};
    std::array<bool,beatsInbar> snareTime =  {1,0,0,0,1,0,1,0};
    std::array<bool,beatsInbar> hatTime =    {0,1,1,0,0,0,1,1};
    
    // How long is a beat?
    float beatTimeInSeconds = 1.0/(BPM / 60.0);
    int beatTimeInSamples = (int) beatTimeInSeconds * sampleRate;
    int outputBufferLength = beatTimeInSamples * beatsInbar * numBar;
    
    
    AudioFile<float> outputBuffer;
    outputBuffer.setSampleRate(sampleRate);
    outputBuffer.setAudioBufferSize(1, outputBufferLength);
    
    

    

    
    return 0;
}



