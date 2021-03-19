//
//  main.cpp
//  Week7Lecture
//
//  Created by Charis Cat on 17/03/2021.
//

#include <iostream>
#include "synth.hpp"

int main() {
    float sampleRate = 44100.0f;
    float c = 0.1f;
    
    AudioFile<float> audioBuffer;
    audioBuffer.setSampleRate(sampleRate);
    audioBuffer.setAudioBufferSize(1, 2*sampleRate);
    
    genNoise(audioBuffer, 0.1f);
    lowPassFilter(audioBuffer, c);
    applyEnvelopeAR(audioBuffer, sampleRate, 0.0f, 0.2f);
    
    audioBuffer.save("snareSynth.wav");
    
    clearBuffer(audioBuffer);
    genNoise(audioBuffer, 0.1f);
    highPassFilter(audioBuffer, c);
    applyEnvelopeAR(audioBuffer, sampleRate, 0.0f, 0.1f);
    
    audioBuffer.save("hihat.wav");
    
    clearBuffer(audioBuffer);
    genSinWave(audioBuffer, sampleRate, 55.0f, 0.1f);
    genSinWave(audioBuffer, sampleRate, 65.0f, 0.05f);
    genSinWave(audioBuffer, sampleRate, 70.0f, 0.05f);
    genSinWave(audioBuffer, sampleRate, 79.0f, 0.1f);
    applyEnvelopeAR(audioBuffer, sampleRate, 0.0f, 0.15f);
    
    audioBuffer.save("kickSynth.wav");

    
    std::cout << "Hello, World!\n";
    return 0;
}
