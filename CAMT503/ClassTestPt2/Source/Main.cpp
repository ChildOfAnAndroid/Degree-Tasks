/*
  ==============================================================================

    This file contains the basic startup code for a JUCE application.

  ==============================================================================
*/

#include <JuceHeader.h>

class MidiMessage {
private:
    int noteNumber;
    int velocity;
    int timeStamp;
    static int objectCount;
    
protected:
    
public:
    void setNoteNumber (int n){
        noteNumber = n;
    }
    
    bool operator > (MidiMessage m) {
        if (this->noteNumber > m.noteNumber)
        {
            return true;
        }

        else return false;
    }
    
    bool operator <= (MidiMessage m) {
        if (this->noteNumber <= m.noteNumber)
        {
            return true;
        }

        else return false;
    }
    
    MidiMessage(int noteNumber) {
        
        objectCount++;
    }
    
};

//==============================================================================
int main (int argc, char* argv[])
{

    // ..your code goes here!
    //MidiMessage m1 = MidiMessage(25);
    //MidiMessage m2 = MidiMessage(26);

    return 0;
}
