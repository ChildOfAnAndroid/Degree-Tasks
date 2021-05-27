//
//  main.cpp
//  week9Lecture
//
//  Created by Charis Cat on 24/03/2021.
//

#include <iostream>
#include "AudioFile.h"
#include <cmath>

float toDB(float input)
{
    float dBValue = 20 * log10(input/1.0f);
    return dBValue;
}

float calculateRMS(const AudioFile<float>& audioBuffer)
{
    //Calculate the RMS
        //square every value in the audio buffer, then take the mean average, then take the square root.
    
    float squaredTotal = 0.0f;
    for (int sample = 0; sample < audioBuffer.getNumSamplesPerChannel(); sample++)
    {
        squaredTotal += pow(audioBuffer.samples[0][sample],2);
    }
    float averageValue = squaredTotal/audioBuffer.getNumSamplesPerChannel();
    float RMS = sqrt(averageValue);
    float RMS_dB = toDB(RMS);
    
    return RMS_dB;
}


int main(int argc, const char * argv[]) {
    
    AudioFile<float> audioBuffer;
    
    audioBuffer.load("snare.wav");
    audioBuffer.printSummary();
    
    float snareRMS = calculateRMS(audioBuffer);
    std::cout << "Snare RMS in dB: " << snareRMS << std::endl;
    
    return 0;
}
