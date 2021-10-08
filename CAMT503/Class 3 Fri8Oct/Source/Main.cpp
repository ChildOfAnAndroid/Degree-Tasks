/*
  ==============================================================================

    This file contains the basic startup code for a JUCE application.

  ==============================================================================
*/

#include <JuceHeader.h>

struct Guitar
{
    int number_of_strings;
    std::string shape, color;
    bool drop_d;
    
    Guitar()
        : number_of_strings(6), shape("Flying V"), color("black"), drop_d(false)
    {}
    
    Guitar(int n)
        : number_of_strings(n), shape("Flying V"), color("black"), drop_d(false)
    {}
    
    Guitar(std::string s)
        : number_of_strings(6), shape(s), color("black"), drop_d(false)
    {}
};

//==============================================================================
int main (int argc, char* argv[])
{

    // ..your code goes here!
    Guitar g1, g2(7), g3("stratocaster");
    std::cout << g1.number_of_strings << std::endl;
    std::cout << g2.number_of_strings << std::endl;
    std::cout << g3.shape << std::endl;

    return 0;
}
