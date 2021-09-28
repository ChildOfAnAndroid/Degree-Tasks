/*
  ==============================================================================

    This file contains the basic startup code for a JUCE application.

  ==============================================================================
*/

#include <JuceHeader.h>

//==============================================================================
int main (int argc, char* argv[]){

//CHARACTERS IN A NAME
    
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
    
    
//IS IT IN C MAJ SCALE??
    
    for(int i = 0; i < 100; i++){
        
//input note
        std::string note;
        std::cout << "Enter Note: ";
        std::cin >> note;
    
//is the note in CMaj scale?
        std::string CMaj[] = {"A", "B", "C", "D", "E", "F", "G"};
    
//output whether the note is in CMaj
        std::cout << "The note ";
        std::cout << note;
            //if yes then 'is' if no then 'is not'
        if(note == CMaj[0]){
                std::cout << "is";
            }
            else{
                std::cout << "is not";
            }
        
        std::cout << " in CMaj" << std::endl;

//stop loop if note name is greater than 2 characters
        if (note.length() > 2){
            break;
        };
        
    } //for end
    
    return 0;
    
} //main end
