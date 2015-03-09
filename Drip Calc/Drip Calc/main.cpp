/*
 Name : Toroid Calculator
 Author: Ben Rockhold
 Date: 03/08/15
 Description: Dopamine drip calculator; requests desired dose and patient weight, checks for safety and returns drips per minute.
 */

//#include <cstdio>       // printf
#include <fstream>      // fileIO
#include <iostream>     // cin/cout
#include <string>       // string operations
using namespace std;


// Helper function writes both to cout and a file
//void record(float weight, int dosage, float dripRate){
//    ofstream dosage_record("dosage_record.txt");
//    if (dosage_record.is_open()){
//        
//        cout << "foo";
//        dosage_record << "foo";
//        
//        dosage_record.close();
//    }
//    
//}




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

// Ask user for intended dosage, accept only integers that pass validateDose()
float getDosage(){
    float dose;
    bool valid;
    do {
        cout << "Please enter the desired dosage in mcg/kg/min: ";
        cin >> dose;
        valid = validateDose(dose);
        if (!valid){
            cout << "Sorry, this dosage is not valid." << endl;
            cout << "Check that the dose is an integer between 5-10 mcg/kg/min." << endl;
        }
    } while (!valid);
    return dose;
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

// Calculate drops per minute
float dropCalculator(float weight, float dosage){
    return weight * dosage * 0.075;
}


// Using above functions, process input and produce dosage rates
int main(int argc, char *argv[]) {
    cout.precision(2);
    ofstream dosage_report("dosage_report.txt");
    float weight;
    float dosage;
    float dripRate;
    dosage = getDosage();
    weight = getWeight();
    dripRate = dropCalculator(weight, dosage);
    cout << endl << "Administer " << dripRate << " drops per minute." << endl;
    //record(weight, dosage, dripRate);
    return 0;
} // End Main

