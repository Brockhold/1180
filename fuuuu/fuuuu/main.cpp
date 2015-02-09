//
//  main.cpp
//  first
//
//  Created by Ben Rockhold on 2/3/15.
//  No rights reserved.
//

#include <iostream>

using namespace std;
int main() {
    string first, last;
    cout << "Please enter your first and last name." << endl;
    cout << "Do not forget to press ENTER" << endl;
    
    cin >> first >> last;
    
    cout << "\nThis is my first program!" << endl;
    cout << "My name is: " << first << " " << last << endl;
    //system ("pause"); // Only required on Windows. Probably should be inside an ifdef, or replace cin with cin.get()
    return 0;
} // end main}
