/*
  ==============================================================================

    This file contains the basic startup code for a JUCE application.

  ==============================================================================
*/

#include <JuceHeader.h>

struct Guitar
{
private: //declaring these as private so that they cannot be edited by other functions in the program
    int number_of_strings;
    std::string shape, color;
    bool drop_d;
    
public:
    Guitar()
        : number_of_strings(6), shape("Flying V"), color("black"), drop_d(false)
    {}
    
    Guitar(int n)
        : number_of_strings(n), shape("Flying V"), color("black"), drop_d(false)
    {}
    
    Guitar(std::string s)
        : number_of_strings(6), shape(s), color("black"), drop_d(false)
    {}
    
    int get_number_of_strings()
    {
        return number_of_strings;
    }
    
    std::string get_shape()
    {
        return shape;
    }
};

struct Keyboard
{
    
};

class Drum
{
protected:
    float skin_tension;
    std::string color;
    float diameter;
    
public:
    float get_diameter()
    {
        return diameter;
    }
};

class Snare : public Drum
{
    float wire_tension;
    
    void play_rim_shot();
};

class Kick : public Drum
{
    bool muffler;

    void play_L_kick();
};

//==============================================================================
int get_color(int note)
{
    int midi_to_color[12] = {0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0};
    return midi_to_color[note];
}

int main (int argc, char* argv[])
{

    // ..your code goes here!
    Guitar g1, g2(7), g3("stratocaster");
    std::cout << g1.get_number_of_strings() << std::endl;
    std::cout << g2.get_number_of_strings() << std::endl;
    std::cout << g3.get_shape() << std::endl;
    
    int note;
    
    while(std::cin >> note)
    {
        std::cout << "Color:" << get_color(note) << std::endl;
    }
    
    return 0;
}

