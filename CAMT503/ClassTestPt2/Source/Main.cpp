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
    
    int getNoteNumber(){
        return noteNumber;
    }
    
    MidiMessage(int noteNumber) {
        //noteNumber = getNoteNumber();
        std::cout << "Constructor Called" << std::endl;
        objectCount++;
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
    
    static int getObjectCount() {
        return objectCount;
    }
};

int MidiMessage::objectCount = 0;

//==============================================================================
int main (int argc, char* argv[])
{

    // ..your code goes here!
    //MidiMessage m1 = MidiMessage(25);
    //MidiMessage m2 = MidiMessage(26);
    
    MidiMessage m1(8), m2(6), m3(8);
    
    std::cout << m1.getObjectCount() << std::endl;
    
    if (m1 <= m2)
    {
        std::cout << "The first note is smaller";
    }
    
    else if (m1 > m2)
    {
        std::cout << "The second note is smaller";
    }

    else
        std::cout << "NO!!";

    
    

    return 0;
}
