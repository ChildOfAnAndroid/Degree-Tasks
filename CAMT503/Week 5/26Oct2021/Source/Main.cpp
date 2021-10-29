/*
  ==============================================================================

    This file contains the basic startup code for a JUCE application.

  ==============================================================================
*/

#include <JuceHeader.h>

//==============================================================================
enum class Colour
{
    red,
    green,
    blue,
};

int main (int argc, char* argv[])
{

    // ..your code goes here!
    Colour c = Colour::red;
    
    switch (c)
    {
        case Colour::red:
            std::cout << "Colour is red!";
            break;
        case Colour::green:
            std::cout << "Colour is green!";
            break;
        case Colour::blue:
            std::cout << "Colour is blue!";
            break;
        default:
            break;
    }


    return 0;
}
