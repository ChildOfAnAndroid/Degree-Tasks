//
//  main.cpp
//  LargestNumberOverload
//
//  Created by Charis Cat on 26/02/2021.
//

#include <iostream>
using namespace std;
double a;
double b;

int main() {
    cin >> a >> b;
    if(a>b){
        cout << a;
    }
    else if(b>a){
        cout << b;
    }
    return 0;
}

