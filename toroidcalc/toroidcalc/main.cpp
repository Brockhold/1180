/*
 Name : Toroid Calculator
 Author: Ben Rockhold
 Date: 02/20/15
 Description: Calculate the volume and surface area for each toroid in a given set.
*/

#include <iostream>
#include <math.h>
using namespace std;

// We use pi^2 a few times
static float pipi = pow(M_PI,2);

// Function accepts r,R for a torus, and returns its volume
float torus_volume(float r,float R){
    return 2*pipi*R*r*r;
}

// Function accepts r,R for a torus, and returns its area
float torus_area(float r,float R){
    return 4*pipi*R*r;
}

// Function accepts r,R for a torus, and returns its hole's area
float hole_area(float r,float R){
    return M_PI*(R-r)*(R-r);
}

int main(int argc, char *argv[]) {
    // Format r,R where r is the radius of the tube, and R is the radius of the torus.
    float toroids [][2] = {
        {1.0,4.0},
        {0.5,1.5},
        {0.5,4.0},
        {5.0,10.0},
        {1.0,10.0},
        {10.0,100.0},
        {1.0,417.0},
        {M_PI,pipi},
        {1.0,42.0},
        {12.0,100.0},
    };
    for(int i = 0; i <  sizeof(toroids)/sizeof(toroids[0]); i++){
        auto toroid = toroids[i];
        cout << "\nWhen the radius of the torus (R) is "<<toroid[1] << "cm ";
        cout << "and the radius of the tube (r) is\n" << toroid[0] << "cm ";
        cout << "the volume is " << torus_volume(toroid[0],toroid[1]) << "cm squared";
        cout << " and its surface area is\n" << torus_area(toroid[0], toroid[1]) << "cc. ";
        cout << "The area of the hole is " << hole_area(toroid[0], toroid[1]) << "cm squared.\n";
    }
    return EXIT_SUCCESS;
} // End Main
