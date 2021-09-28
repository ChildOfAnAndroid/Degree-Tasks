/*
  ==============================================================================

    This file contains the basic startup code for a JUCE application.

  ==============================================================================
*/

#include <JuceHeader.h>

//==============================================================================
int main (int argc, char* argv[]){

    for(int i = 0; i < 100; i++){
        
//input name
        std::string name;
        std::cout << "Enter Name: ";
        std::cin >> name;
    
//count characters
        int charCount;
        charCount = name.length();
    
//output number of characters in name
        std::cout << "The name ";
        std::cout << name;
        std::cout << " has ";
        std::cout << charCount;
        std::cout << " characters" << std::endl;

//stop loop when name length 1
        if (name.length() < 2){
            break;
        };
        
    } //for end
    
    return 0;
    
} //main end
