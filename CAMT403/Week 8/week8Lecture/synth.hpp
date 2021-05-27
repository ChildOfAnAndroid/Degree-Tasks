//
//  synth.hpp
//  Week6Lab
//
//  Created by David Moffat on 12/03/2021.
//  Copyright © 2021 DavidMoffat. All rights reserved.
//

#ifndef synth_hpp
#define synth_hpp

#include "AudioFile.h"

void operator+=(AudioFile<float>& audioBuffer, const AudioFile<float>& audioBuffer2);
void applyEnvelopeAR(AudioFile<float>& audioBuffer, float sampleRate, float attackTime, float releaseTime);
void genNoise(AudioFile<float>& audioBuffer, float amplitude);
void genSinWave(AudioFile<float>& audioBuffer, float sampleRate, float frequency, float amplitude);
float interp(float startVal, float endVal, float val);
void lowPassFilter(AudioFile<float>& audioBuffer, float filterCoefficient);
void highPassFilter(AudioFile<float>& audioBuffer, float filterCoefficient);
void clearBuffer(AudioFile<float>& audioBuffer);

#endif /* synth_hpp */
