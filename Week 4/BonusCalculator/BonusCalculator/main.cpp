//
//  main.cpp
//  BonusCalculator
//
//  Created by Charis Cat on 24/02/2021.
//

#include <iostream>
using namespace std;

int salary = 0;

int main() {
    cin >> salary;
    if(salary>=25000){
        cout << salary*1.15 << endl;
    }
    else if(salary>=20000 && salary<25000){
        cout << salary*1.1 << endl;
    }
    else(salary<20000);{
        cout << salary*1.05 << endl;
    }
    return 0;
}
