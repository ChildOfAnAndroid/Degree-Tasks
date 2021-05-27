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


// QUESTION ONE
//code for question one here
int numDouble(int num) { //initialise variable to be doubled
    int dub; //initialise doubled variable
    dub = num*2; //the doubled value is two times the initial value
    return dub; //return the doubled value
}

// QUESTION TWO
//code for question two here
void refNumDouble(int& referencedNum) { //initialise referenced value to be doubled
    referencedNum = referencedNum*2; //the doubled value is two times the initial value
    cout << referencedNum;
}

// QUESTION THREE
//code for question three here
double rectangleArea(double a, double b) { //initialise two double variables in a double function
    double area;
    area = a*b;
    return area;
}

// QUESTION FOUR
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
int smallestValue(array<int, 10> numbers) {
    int smallestResult = INT_MAX; //initialise smallest result as high as possible, so any new value is smaller
    for(int index = 0; index < 10; index++) { //loop through all elements in array
        if (numbers[index] < smallestResult) { //if the current array value is smaller than current smallest....
            smallestResult = numbers[index]; //save that variable as the new smallest
        }
    }
    return smallestResult;
}

// QUESTION SIX
//code for question SIX here
float audioRMS (array<float,8> testData) {
    
    float squareTotalRMS = 0;
    float meanTotalRMS = 0;
    float resultRMS = 0;
    
    for (int index = 0; index < 8; index++){
            squareTotalRMS += pow(testData[index],2);
        } //square each individual value of the signal
    
    meanTotalRMS = squareTotalRMS/8; //calculate the average(mean) squared signal
    
    resultRMS = sqrt(meanTotalRMS); //calculate the square root of the mean
    
    return resultRMS; //return the RMS of the signal
}

// QUESTION SEVEN
//code for question seven here
void arraySort (array<int,10> numbers) { //void type as it does not return a result, but sorts the list directly
    bool swapNumber = true; //initialise as if the last number has been swapped
    
    while(swapNumber == true) { //while the last number in the list was changed (or this is the first number), loop
        swapNumber = false; //The current number has not been changed
        for (int index = 0; index < 9; index++) { //Loop through each number in the array
            if (numbers[index] > numbers[index+1]) { //if the current number is bigger than the next array number
                swap(numbers[index], numbers[index+1]); //swap them
                swapNumber = true;
            }
        }
    }
    for(int i = 0; i < 10; i++) {
        cout << numbers[i] << ", "; //output each number of the sorted array
    }
    cout << endl;
}

// QUESTION EIGHT
//code for question eight here

void fizzBuzz() {
    for(int number = 1; number <= 100; number++) {
        string output = ""; //empty space to indicate when number is not divisible by 3 or 5.
        if (number % 3 == 0) {
            output += "Fizz"; //If number is divisible by 3, output Fizz
        }
        if (number % 5 == 0) {
            output += "Buzz"; //If number is divisible by 5, add Buzz to that output
        }
        if(output == "") { //If nothing has been added to the output, just output the original number
            output = to_string(number); //converts the integer to a string to allow mixing with text in output
        }
        cout << output << endl; //Outputs the list of numbers with Fizz/Buzz/FizzBuzz replacements
    }
}




int main() {
    //QUESTION 1
    int question1;
    question1 = numDouble(5); //Number in brackets will be doubled
    cout << "Question 1: " << question1 << endl;
    
    //QUESTION 2
    int value = 3;
    cout << "Question 2: ";
    refNumDouble(value); //Calls the refNumDouble function
    cout << endl;
    
    //QUESTION 3
    double question3; //using double for this variable so that it outputs as a double
    question3 = rectangleArea(5.33,3.56); //Two numbers in brackets are sides a and b of a rectangle
    cout << "Question 3: " << question3 << endl; //Output area of rectangle using sides a and b
    
    //QUESTION 4
    double question4; //using double for this variable so that it outputs as a double
    question4 = rectangleArea(3.668); //Overloads rectangleArea function if using only one side represnting a square
    cout << "Question 4: " << question4 << endl; //Output area of square using side a
    
    //QUESTION 5
    int question5; //integer output
    question5 = smallestValue({5,8,4,255,6,89,4,37,8,64}); //The 10 values between curly brackets become the array
    cout << "Question 5: " << question5 << endl; //Output lowest value in the above array
    
    //QUESTION 6
    float question6; //float output
    question6 = audioRMS({-0.9, 0.8, -0.6, 0.4, 0.1, 0.6, 0.2, 0.4}); //8 values in curly brackets are audio test data
    cout << "Question 6: " << question6 << endl; //Output the RMS result for the above test data

// For Question 6
//    std::array<float,8> testData = {-0.9, 0.8, -0.6, 0.4, 0.1, 0.6, 0.2, 0.4};
    
    //QUESTION 7
    cout << "Question 7: ";
    arraySort({5,8,4,255,6,89,4,37,8,64}); //Calls the arraySort function
    
    //QUESTION 8
    cout << "Question 8: " << endl;
    fizzBuzz(); //Calls the fizzBuzz Function
    
    
    
    return 0;
}

