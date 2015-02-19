//
//  main.cpp
//  toroidcalc
//
//  Created by Ben Rockhold on 2/18/15.
//  Copyright (c) 2015 Ben Rockhold. All rights reserved.
//
/*
 Calculate the volume and surface area for each toroid in a given set.
 
 */

#include <iostream>
#include <math.h>
using namespace std;

// Honestly this is probably not a good reason to have imported all of math.h
static float pi = M_PI;

// Function accepts r,R for a torus, and returns its volume
float torus_volume(float r,float R){
    return 2*pi*pi*R*r*r;
}

// Function accepts r,R for a torus, and returns its area
float torus_area(float r,float R){
    return 4*pi*pi*R*r;
}

// Function accepts r,R for a torus, and returns its hole's area
float hole_area(float r,float R){
    return pi*(R-r)*(R-r);
}

int main() {
    // Format r,R where r is the radius of the tube, and R is the radius of the torus.
    float toroids [][2] = {
        {1.0,4.0},
        {0.5,1.5},
        {0.5,4.0},
        {5.0,10.0},
        {1.0,10.0},
        {10.0,100.0},
        {1.0,417.0},
        {pi,pi*pi},
        {1.0,42.0},
        {120.0,100.0},
    };
    for(int i = 0; i <  sizeof(toroids)/sizeof(toroids[0]); i++){
        auto toroid = toroids[i];
        cout << "\nWhen the radius of the torus (R) is "<<toroid[1] << "cm ";
        cout << "and the radius of the tube (r) is\n" << toroid[0] << "cm ";
        cout << "the volume is " << torus_volume(toroid[0],toroid[1]) << "cm squared";
        cout << " and its surface area is\n" << torus_area(toroid[0], toroid[1]) << "cc. ";
        cout << "The area of the hole is " << hole_area(toroid[0], toroid[1]) << "cm squared.\n";
    }
    return 0;
}
