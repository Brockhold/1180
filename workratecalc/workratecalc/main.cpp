//
//  main.cpp
//  workratecalc
//
//  Created by Ben Rockhold on 2/5/15.
//  Copyright (c) 2015 Ben Rockhold. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    float hours, rate, net, gross;
    const float tax = 25.0;
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "Hourly rate: ";
    cin >> rate;
    cout << "\nHours worked: ";
    cin >> hours;
    gross = hours * rate;
    net = gross - tax;
    cout << "Net: " << net << " Gross: " << gross << "\n";
    return 0;
}
