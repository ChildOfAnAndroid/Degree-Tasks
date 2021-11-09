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
        
    }
    void setPresetName (std::string n) {
        
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

    }
};

//==============================================================================
int main (int argc, char* argv[])
{

    // ..your code goes here!


    return 0;
}
