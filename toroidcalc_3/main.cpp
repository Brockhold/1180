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
        cout << "\nWhen the radius of the torus (R) is " << toroids[i][1] << "cm ";
        cout << "and the radius of the tube (r) is\n" << toroids[i][0] << "cm ";
        cout << "the volume is " << torus_volume(toroids[i][0],toroids[i][1]) << "cm squared";
        cout << " and its surface area is\n" << torus_area(toroids[i][0], toroids[i][1]) << "cc. ";
        cout << "The area of the hole is " << hole_area(toroids[i][0], toroids[i][1]) << "cm squared.\n";
    }
    return 1;
} // End Main

/*

 === Program Output ===

When the radius of the torus (R) is 4cm and the radius of the tube (r) is
1cm the volume is 78.9568cm squared and its surface area is
157.914cc. The area of the hole is 28.2743cm squared.

When the radius of the torus (R) is 1.5cm and the radius of the tube (r) is
0.5cm the volume is 7.4022cm squared and its surface area is
29.6088cc. The area of the hole is 3.14159cm squared.

When the radius of the torus (R) is 4cm and the radius of the tube (r) is
0.5cm the volume is 19.7392cm squared and its surface area is
78.9568cc. The area of the hole is 38.4845cm squared.

When the radius of the torus (R) is 10cm and the radius of the tube (r) is
5cm the volume is 4934.8cm squared and its surface area is
1973.92cc. The area of the hole is 78.5398cm squared.

When the radius of the torus (R) is 10cm and the radius of the tube (r) is
1cm the volume is 197.392cm squared and its surface area is
394.784cc. The area of the hole is 254.469cm squared.

When the radius of the torus (R) is 100cm and the radius of the tube (r) is
10cm the volume is 197392cm squared and its surface area is
39478.4cc. The area of the hole is 25446.9cm squared.

When the radius of the torus (R) is 417cm and the radius of the tube (r) is
1cm the volume is 8231.25cm squared and its surface area is
16462.5cc. The area of the hole is 543671cm squared.

When the radius of the torus (R) is 9.8696cm and the radius of the tube (r) is
3.14159cm the volume is 1922.78cm squared and its surface area is
1224.08cc. The area of the hole is 142.208cm squared.

When the radius of the torus (R) is 42cm and the radius of the tube (r) is
1cm the volume is 829.047cm squared and its surface area is
1658.09cc. The area of the hole is 5281.02cm squared.

When the radius of the torus (R) is 100cm and the radius of the tube (r) is
12cm the volume is 284245cm squared and its surface area is
47374.1cc. The area of the hole is 24328.5cm squared.

Process returned 1 (0x1)   execution time : 0.002 s
Press ENTER to continue.

*/
