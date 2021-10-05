/*
  ==============================================================================

    This file contains the basic startup code for a JUCE application.

  ==============================================================================
*/

#include <JuceHeader.h>
#include <algorithm>

int transpose_key(int note, int diff)
{
    return note + diff;
}

//==============================================================================
int main (int argc, char* argv[])
{

    // ..your code goes here!
    std::vector<int> c_major_notes;
    int first_octave[7] = {24, 26, 28, 29, 31, 33, 35};
    
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            c_major_notes.push_back(first_octave[j] + i * 12);
        }
    }
    
    for (auto i : c_major_notes)
        std::cout << i << " ";
    
    int note;
    
    std::cin >> note;
    
    auto it = std::find(c_major_notes.begin(), c_major_notes.end(), note);
    
    if (it != c_major_notes.end())
    {
        auto pos = it - c_major_notes.begin();
        std::cout << c_major_notes[pos + 1];
    }
    
    
    //int note, diff;
    
    //std::cout << "Enter MIDI Note: ";
    //std::cin >> note;
    
    //std::cout << "Transpose by: ";
    //std::cin >> diff;
    
    //std::cout << transpose_key(note, diff);
    //std::cout << std::endl;
    

    return 0;
}
