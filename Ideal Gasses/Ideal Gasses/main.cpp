/*
 Name : Ideal Gas Comparator
 Author: Ben Rockhold
 Date: 04/2/15
 Description: Reads in the contents of the file "vanDerWaalsConstants,"
        calculates the percentage error between the Ideal Gas and Van der Waal forumulae
        for the gas at a set of temperatures, and writes a line in the report text
        file "Gasses.csf" for each gas read in.
*/

#include <iostream>
#include <fstream>
using namespace std;

// Returns the pressure for 1 mol/liter of gas at a given temperature
// (using the Ideal Gas formula)
float idealPressure(float temperature){
    // P = R*Temperature/Volume, where R=0.0821
    return 0.0821*temperature;
}

// Returns the pressure for 1 mol/liter of gas at a given temperature
// (using the Van der Waals equation for pressure)
float vanDerWaalsPressure(float temperature, float a, float b){
    // P = (RT)/(V-b) - (a)/(V^2)
    return (0.0821*temperature)/(1-b) - a;
}

// Calculates the percentage difference between the Ideal Gas and Van der Waals formulae
float percentError(float a, float b, float temperature){
    float ideal = idealPressure(temperature=temperature);
    float VdW = vanDerWaalsPressure(temperature=temperature, a=a, b=b);
    float error = (ideal - VdW)/VdW * 100;
    return error;
}

// Writes a gas pressure calculation-percentage-error report.
// For every line of the given ifstream, pass the values to the helper functions above,
// then record the returned error percentage to the given ofstream.
void readConstants(ifstream& inputFile, ofstream& outputFile){
    string gasName;
    float a, b;
    // verify that the input and output files are open
    if ((inputFile.is_open())&(outputFile.is_open())){
        // write the file header
        outputFile << "Gas, Temperature (K), Percentage Error" << endl;
        while (!inputFile.eof()){
            // read each line of the input file as "name, a, b" splitting by whitespace
            inputFile >> gasName >> a >> b;
            // iterate on temperature in range 100-500 in increments of 25
            for (int temperature = 100; temperature <= 500; temperature += 25){
                // record to the output file
                outputFile << gasName << ", "<< temperature << ", " << percentError(a, b, temperature) << endl;
            }
        } // end while (EOF hit, so the function is complete)
    } // end if
}

int main() {
    ofstream vanDerWaalsReport("Gasses.csv");
    vanDerWaalsReport.precision(3);
    ifstream vanDerWaalsConstants("vanDerWaalsConstants");
    readConstants(vanDerWaalsConstants, vanDerWaalsReport);
    return 0;
}
