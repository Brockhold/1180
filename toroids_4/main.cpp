/*
 Name : Toroid Calculator
 Author: Ben Rockhold
 Date: 02/20/15
 Description: Calculate the volume and surface area for each toroid in a given set.
            Expected input is a text file "toroids.txt," each line of which contains
            a pair of decimal numbers representing first the radius of the tube,
            and then the major radius of the torus.
            e.g.
                1.0 4.0
                0.5 1.5
            The program will terminate when presented with either an empty line,
            or an invalid torus. (radius of zero or negative)
            A file named "toroid_report" will be created, with information on the
            volume and surface area of each torus.
*/


#include <math.h>       // Definition of pi
#include <stdlib.h>     // string to double with atof
#include <fstream>      // fileIO
#include <iostream>     // cin/cout
#include <string>       // string operations
using namespace std;

// Identify if a pair of data points makes a valid torus
bool valid_torus(double r,double R){
    if((r <= 0.0) | (R <= 0.0) | (R<r)){
        return false;
    }
    return true;
}

// Function accepts r,R for a torus, and returns its volume
double torus_volume(double r,double R){
    return 2*pow(M_PI,2)*R*r*r;
}

// Function accepts r,R for a torus, and returns the surface area
double torus_area(double r,double R){
    return 4*pow(M_PI,2)*R*r;
}

// Function accepts r,R for a torus, and returns the area of the hole
double hole_area(double r,double R){
    return M_PI*(R-r)*(R-r);
}

// Write information about the toroid r,R to the file passed
void write_report(ofstream& file,double r, double R){
    file << "\nWhen the radius of the torus (R) is " << R << "cm ";
    file << "and the radius of the tube (r) is\n" << r << "cm ";
    file << "the volume is " << torus_volume(r,R) << "cm squared";
    file << " and its surface area is\n" << torus_area(r, R) << "cc. ";
    file << "The area of the hole is " << hole_area(r, R) << "cm squared.\n";
}

// Read the "toroid_data" file and create "toroid_report" file
int main(int argc, char *argv[]) {
    // a and b are extracted from each line in the toroid_data file
    char a[256],b[256];
    ifstream toroid_data("toroids.txt");
    ofstream toroid_report("toroid_report.txt");
    if((toroid_data.is_open())&(toroid_report.is_open())){
        while(toroid_data >> a >> b){
            // cout << "r= " << a << " and R= " << b << endl;
            double r = atof(a);
            double R = atof(b);
            if(valid_torus(r,R)){
                write_report(toroid_report,r,R);
            }
            else return 1; // The data read is not valid, terminate with error
        }
    toroid_data.close();
    toroid_report.close();
    }
    return 0;
} // End Main

/* Unused functions for replacing the main function with a variant based on user input rather than file reading

// Prompt user for 'r,' the toroid's minor radius
double get_minor_radius(){
    double r;
    cout << "Enter Minor radius (0 to exit): ";
    cin >> r;
return r;
}

// Prompt user for 'R,' the toroid's major radius
double get_major_radius(){
    double R;
    cout << "Enter Major radius: ";
    cin >> R;
return R;
}

int main(){
    double r, R;
    ofstream toroid_report("toroid_report.txt");
    if(toroid_report.is_open()){
        while((r < 0.0)&(R < 0.0)){
            r = get_minor_radius();
            R = get_major_radius();
            if(valid_torus(r,R)){
                write_report(toroid_report,r,R);
            }
            else return 1; // The data read is not valid, terminate with error
        }
    toroid_report.close();
    }
    return 0;
}
*/

