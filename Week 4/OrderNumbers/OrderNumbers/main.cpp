//
//  main.cpp
//  OrderNumbers
//
//  Created by Charis Cat on 26/02/2021.
//

#include <iostream>
using namespace std;
int numbers[3];
int sorted[3];

int main() {
    cin >> numbers[0] >> numbers [1] >> numbers [2];
    
    if(numbers[0]>numbers[1] && numbers[0]>numbers[2]){
        sorted[2] = numbers[0];
        if(numbers[1]<numbers[2]){
            sorted[0] = numbers[1];
            sorted[1] = numbers[2];
        }
        else {
            sorted[0] = numbers[2];
            sorted[1] = numbers[1];
        }
    }
    else if(numbers[1]>numbers[2]){
        sorted[2] = numbers[1];
        if(numbers[2]<numbers[0]){
            sorted[0] = numbers[2];
            sorted[1] = numbers[0];
        }
        else {
            sorted[0] = numbers[0];
            sorted[1] = numbers[2];
        }
    }
    else {
        sorted[2] = numbers[2];
        if(numbers[1]<numbers[0]){
            sorted[0] = numbers[1];
            sorted[1] = numbers[0];
        }
        else {
            sorted[1] = numbers[0];
            sorted[0] = numbers[1];
        }
        
    }
    
    cout << sorted[0] << " " << sorted[1] << " " << sorted[2] << endl;
    return 0;
}

