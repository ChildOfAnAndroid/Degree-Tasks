//
//  classTest.cpp
//  classTest
//
//  Created by Charis Cat on 08/03/2021.
//

#include <iostream>
#include <array>
#include <cmath>
#include <climits>
using namespace std;


// QUESTION ONE (complete) (unchecked)
//code for question one here
int numDouble(int num) { //initialise variable to be doubled
    int dub; //initialise doubled variable
    dub = num*2; //the doubled value is two times the initial value
    return dub; //return the doubled value
}

// QUESTION TWO
//code for question two here
void refNumDouble(int &num) { //initialise referenced value to be doubled
    num = num*2; //the doubled value is two times the initial value
}

// QUESTION THREE (complete) (unchecked)
//code for question three here
double rectangleArea(double a, double b) { //initialise two double variables in a double function
    double area;
    area = a*b;
    return area;
}

// QUESTION FOUR (complete) (unchecked)
//code for question four here
double rectangleArea(double a) {
    double area;
    area = pow(a,2);
    return area;
}

// QUESTION FIVE
/* psuedocode --
   loop through all elements in array
   compare each value to the one after it, saving that to a 'smallest value' variable if it is smaller
   return the smallest value
    */
//code for question FIVE here
int smallestValue(array<int, 10> numbers = {5,8,4,2,6,89,1,2,8,64}) {
    for(int arrayValue = 0; arrayValue < 10; arrayValue++) { //loop through all elements in array
        cout << arrayValue << endl;
    }
    return 0;
}

// QUESTION SIX
//code for question SIX here

// QUESTION SEVEN
//code for question seven here

// QUESTION EIGHT
//void FizzBuzz()
//{
//code for question eight here
//}




int main() {
    //QUESTION 1 (complete) (unchecked)
    int question1;
    question1 = numDouble(5); //Number in brackets will be doubled
    cout << "Question 1: " << question1 << endl;
    
    //QUESTION 2
    /*int question2;
    question2 = refNumDouble(5); //Number in brackets will be doubled
    cout << "Question 2: " << question2 << endl;*/
    cout << "Question 2: " << endl;
    
    //QUESTION 3 (complete) (unchecked)
    double question3; //using double for this variable so that it outputs as a double
    question3 = rectangleArea(5.33,3.56); //Two numbers in brackets are sides a and b of a rectangle
    cout << "Question 3: " << question3 << endl; //Output area of rectangle using sides a and b
    
    //QUESTION 4 (complete) (unchecked)
    double question4; //using double for this variable so that it outputs as a double
    question4 = rectangleArea(3.668); //Overloads rectangleArea function if using only one side represnting a square
    cout << "Question 4: " << question4 << endl; //Output area of square using side a
    
    //QUESTION 5
    //int question5;
    //question5 = smallestValue(array<int,10>);
    //cout << "Question 5: " << question5 << endl;

// For Question 6
//    std::array<float,8> testData = {-0.9, 0.8, -0.6, 0.4, 0.1, 0.6, 0.2, 0.4};

    return 0;
}

