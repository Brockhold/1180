/*
 Name: Homework 0
 Author: Ben Rockhold
 Date: 2015-02-03-09.30
 Description: This is the first assignment of CISC 1180
*/

#include <iostream>
using namespace std;

int main() {
    string first, last;
    cout << "Please enter your first and last name:" << endl;
    cout << "Do not forget to press ENTER" << endl;
    
    cin >> first >> last;
    
    cout << "\nThis is my first program!" << endl;
    cout << "My name is: " << first << " " << last << endl;
    //system ("pause"); // Only required on Windows. Probably should be inside an ifdef, or replace cin with cin.get()
    return 0;
} // end main}


/*

 ////   Expected output:
 
 Please enter your first and last name:
 Do not forget to press ENTER
 Ben Rockhold
 
 This is my first program!
 My name is: Ben Rockhold
 Program ended with exit code: 0

*/