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

// Receive torus specification from a user
pair<float, float> userInput(void){
    float major, minor;
    cout << "Enter the toroid's major and minor radii -- enter 0 for either to exit.";
    cout << "\nMajor Radius: ";
    cin >> major;
    cout << "\nMinor (tube) radius: ";
    cin >> minor;
    return 0:
}

// Function accepts r,R for a torus, and returns its volume
float torusVolume(float r,float R){
    return 2*pipi*R*r*r;
}

// Function accepts r,R for a torus, and returns its area
float torusArea(float r,float R){
    return 4*pipi*R*r;
}

// Function accepts r,R for a torus, and returns its hole's area
float holeArea(float r,float R){
    return M_PI*(R-r)*(R-r);
}

int main(int argc, char *argv[]) {
    // Format r,R where r is the radius of the tube, and R is the radius of the torus.
    float foo, bar;
    foo, bar = userInput();
    cout << foo, bar;
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
        cout << "the volume is " << torusVolume(toroid[0],toroid[1]) << "cm squared";
        cout << " and its surface area is\n" << torusArea(toroid[0], toroid[1]) << "cc. ";
        cout << "The area of the hole is " << holeArea(toroid[0], toroid[1]) << "cm squared.\n";
    }
    return EXIT_SUCCESS;
} // End Main
