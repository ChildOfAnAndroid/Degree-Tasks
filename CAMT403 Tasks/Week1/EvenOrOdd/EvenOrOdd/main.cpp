//
//  main.cpp
//  EvenOrOdd
//
//  Created by Charis Cat on 05/02/2021.
//

#include <iostream>

void evenOrOdd(int number){
    if(number % 2 == 0)
        std::cout << "even \n";
    else
        std::cout << "odd \n";
}

int main() {
        for (int i = 1; i <= 10; ++i) {
            evenOrOdd(i);
    }
    return 0;
}
