/*
 Name : Dopamine Drip Calculator v2
 Author: Ben Rockhold
 Date: 03/08/15
 Description: Dopamine drip calculator; requests desired dose and patient weight, checks for safety and returns drips per minute. 
    Additionally, outputs user input and calculation output to a file "dosage_report.txt"
 */


#include <fstream>      // fileIO
#include <iostream>     // cin/cout
using namespace std;

// Validate a patient's weight is > 0
bool validateWeight(float weight){
    if (weight < 0.0) return 0;
    return 1;
}

// Ask for patient's weight (kg)
float getWeight(){
    float weight;
    bool validWeight;
    do {
        cout << "Please enter patient's weight (kg): ";
        cin >> weight;
        validWeight = validateWeight(weight);
        if (!validWeight){
            cout << endl << "Invalid weight (sub-0) entered." << endl;
        }
    } while (!validWeight);
    return weight;
}

// From a weight and total dosage, calculate dosage rate in drops per minute
float dropCalculator(float weight, float dosage){
    return weight * dosage * 0.075;
}

// Using a patient weight, generate a table of dosage rates
void dosageTable(float weight){
    ofstream dosage_report("dosage_report.txt");
    float dosage;
    if (dosage_report.is_open()){
        cout << endl << "Dose (mg/kg/min)\tGTT/Minute" << endl << endl;
        dosage_report << "Dosage table for a patient of " << weight << "kg";
        dosage_report << endl << "Dose (mg/kg/min)\tGTT/Minute" << endl << endl;
        for(int i = 5; i<=10; i++){
            dosage = dropCalculator(weight, i);
            cout << "\t" << i << "\t\t\t\t\t" << dosage << endl;
            dosage_report << "\t" << i << "\t\t\t\t\t" << dosage << endl;
        }
    }
}

// Using above functions, process input and produce dosage rates
int main(int argc, char *argv[]) {
    cout.precision(2);
    ofstream dosage_report("dosage_report.txt");
    float weight;
    weight = getWeight(); // Ask the user for the patient's weight
    dosageTable(weight);
    return 0;
} // End Main
