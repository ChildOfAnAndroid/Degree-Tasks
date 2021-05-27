//
//  main.cpp
//  AreaOfTriangle
//
//  Created by Charis Cat on 24/02/2021.
//

#include <iostream>
using namespace std;

float A, s, a, b, c;

int main() {
    
    cin >> a >> b >> c;
    
    s = (a+b+c)/2;
    
    A = sqrt(s*(s-a)*(s-b)*(s-c));
    
    cout << A;
    
    return 0;
}
