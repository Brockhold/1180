/*
 Name : Dopamine Drip Calculator
 Author: Ben Rockhold
 Date: 03/08/15
 Description: Dopamine drip calculator; requests desired dose and patient weight, checks for safety and returns drips per minute.
 */


#include <fstream>      // fileIO
#include <iostream>     // cin/cout
using namespace std;

// Validate drops per minute given a defined safety level
bool validateDose(float dose){
    if (5.0 <= dose & dose <= 10.0) return 1;
    return 0;
}

// Validate a patient's weight is > 0
bool validateWeight(float weight){
    if (weight < 0.0) return 0;
    return 1;
}

// Ask user for intended dosage, accepts only values that pass validateDose()
float getDosage(ofstream& log_file){
    float dose;
    bool valid;
    const string error_msg = "Sorry, this dosage is not valid. \nCheck that the dose is an integer between 5-10 mcg/kg/min.";
    do {
        cout << "Please enter the desired dosage in mcg/kg/min: ";
        log_file << "Please enter the desired dosage in mcg/kg/min: ";
        cin >> dose;
        log_file << dose << endl;
        valid = validateDose(dose);
        if (!valid){
            cout << error_msg << endl;
            log_file << error_msg << endl;
        }
    } while (!valid);
    return dose;
}

// Ask for patient's weight (kg)
float getWeight(ofstream& log_file){
    float weight;
    const string request_msg = "Please enter patient's weight (kg): ";
    const string error_msg = "Invalid weight (sub-0) entered.";
    bool validWeight;
    do {
        cout << request_msg;
        log_file << request_msg;
        cin >> weight;
        log_file << weight << endl;
        validWeight = validateWeight(weight);
        if (!validWeight){
            cout << endl << error_msg << endl;
            log_file << error_msg << endl;
        }
    } while (!validWeight);
    return weight;
}

// Calculate drops per minute
float dropCalculator(float weight, float dosage){
    return weight * dosage * 0.075;
}


// Using above functions, process input and produce dosage rates
int main(int argc, char *argv[]) {
    cout.precision(2);
    float weight;
    float dosage;
    float dripRate;
    ofstream dosage_report("dosage_report.txt", ios::app);
    if (dosage_report.is_open()){
        dosage = getDosage(dosage_report); // Ask the user for the intended dosage
        weight = getWeight(dosage_report); // Ask the user for the patient's weight
        dripRate = dropCalculator(weight, dosage); // Calculate the appropriate drip rate
        dosage_report << "To give a dose of "<< dosage <<"mg/kg/min to a " << weight << "kg patient, ";
        dosage_report << "administer " << dripRate << " drops per minute." << endl << endl;
        cout << endl << "Administer " << dripRate << " drops per minute." << endl;
    }
    return 0;
} // End Main

