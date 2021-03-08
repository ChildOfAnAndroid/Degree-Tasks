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
int numDouble(int num) {
    int dub;
    dub = num*2;
    return dub;
}

// QUESTION TWO
//code for question two here
void refNumDouble(int &num) {
    num = num*2;
}

// QUESTION THREE
//code for question three here

// QUESTION FOUR
//code for question four here

// QUESTION FIVE
//code for question FIVE here

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
    int question1;
    question1 = numDouble(5); //Number in brackets will be doubled
    cout << "Question 1: " << question1 << endl;
    
    int question2;
    question2 = refNumDouble(5); //Number in brackets will be doubled
    cout << "Question 2: " << question2 << endl;

// For Question 6
//    std::array<float,8> testData = {-0.9, 0.8, -0.6, 0.4, 0.1, 0.6, 0.2, 0.4};

    return 0;
}

