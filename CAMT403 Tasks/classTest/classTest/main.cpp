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

// QUESTION FIVE (completed) (unchecked)
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
int arraySort (array<int,10> numbers) { //void type as it does not return a result, but sorts the list directly
    bool swapNumber = true; //initialise as if the last number has been swapped
    if(swapNumber == true) { //If the last number in the list was changed (or this is the first number) loop
        swapNumber = false; //The current number has not been changed
        for (int index = 0; index < 10; index++) { //Loop through each number in the array
            if (numbers[index] > numbers[index+1]) { //if the current number is bigger than the next array number
                swap(numbers[index], numbers[index+1]); //swap them
                swapNumber = true;
            }
        }
    }
    return 0;
}


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
    
    //QUESTION 5 (complete) (unchecked)
    int question5; //integer output
    question5 = smallestValue({5,8,4,255,6,89,4,37,8,64}); //The 10 values between curly brackets become the array
    cout << "Question 5: " << question5 << endl; //Output lowest value in the above array
    
    //QUESTION 6 (complete) (unchecked)
    float question6; //float output
    question6 = audioRMS({-0.9, 0.8, -0.6, 0.4, 0.1, 0.6, 0.2, 0.4}); //8 values in curly brackets are audio test data
    cout << "Question 6: " << question6 << endl; //Output the RMS result for the above test data

// For Question 6
//    std::array<float,8> testData = {-0.9, 0.8, -0.6, 0.4, 0.1, 0.6, 0.2, 0.4};
    
    //QUESTION 7
    int question7; //integer output
    question7 = arraySort({5,8,4,255,6,89,4,37,8,64}); //The 10 values between curly brackets will be sorted
    cout << "Question 7: ";
    for(int index = 0; index < 10; index++) {
        cout << /* how do i access the sorted array!? << */ ", "; //output each number of the sorted array
    }
    cout << endl;

    return 0;
    
    //QUESTION 8
}

