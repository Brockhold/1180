//
//  main.cpp
//  agecalc
//
//  Created by Ben Rockhold on 2/5/15.
//  Copyright (c) 2015 Ben Rockhold. All rights reserved.
//

/*
Take month and year of birth, and month and year of the present, and return the age.
Do this until receiving an invalid value (0) for month.
*/

#include <iostream>
using namespace std;

int calcage(){
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    float birthmonth, birthyear, currentmonth, currentyear, age;
    cout << "Birth month: ";
    cin >> birthmonth;
    if(birthmonth == 0){
        cout << "Invalid value (0), terminating.\n";
        return 0;
    }
    cout << "Birth year: ";
    cin >> birthyear;
    cout << "Current month: ";
    cin >> currentmonth;
    cout << "Current year: ";
    cin >> currentyear;
    age = currentyear-birthyear + (currentmonth-birthmonth)/12;
    cout << "Your age is " << age << "\n";
    return 1;
}

int main() {
    int flag;
    flag = calcage();
    while(flag!=0){
        flag = calcage();
    }
    return 0;
}
