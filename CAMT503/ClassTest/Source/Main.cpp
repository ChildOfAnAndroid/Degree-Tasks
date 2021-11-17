/*
  ==============================================================================

    This file contains the basic startup code for a JUCE application.

  ==============================================================================
*/

#include <JuceHeader.h>

class SoundEffect {
private:
    
protected:
    int bufferSize;
    float inputGain;
    std::string presetName;
    
public:
    void setGain (float g) {
        inputGain = g;
    }
    void setPresetName (std::string n) {
        presetName = n;
    }
    
    //constructor
    SoundEffect(int bufferSize){
        bufferSize = 256;
    }
};

class Reverb:public SoundEffect {
private:
    float roomLength;
    float roomWidth;
    float roomHeight;
    
protected:
    
public:
    float getRoomVolume() {
        return (roomLength*roomWidth)*roomHeight;
    }
    
   Reverb(int length) :public SoundEffect(bufferSize)
        :roomLength(length){
        
    }
    
    Reverb(int length, int width, int height) :public SoundEffect(bufferSize)
        :roomLength(length), roomWidth(width), roomHeight(height){
        
    }
};

//==============================================================================
int main (int argc, char* argv[])
{

    // ..your code goes here!
    Reverb r1(int length);
    Reverb r2(int length, int width, int height);

    return 0;
}
