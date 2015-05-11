/*
 Name : HNR1 Processor
 Author: Ben Rockhold
 Date: 05/5/15
 Description:
    Does stuff with some files.
 */

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

const int RNAArrayLength = 64;


void readRNACodonTable(ifstream & inFile, string codonArray[RNAArrayLength][2]){
    string a, b;
    if (inFile.is_open()){
        for (int i=0; i < RNAArrayLength; i++){
            inFile >> a >> b;
            codonArray[i][0] = a;
            codonArray[i][1] = b;
        }
    }
}


int main() {
    string codonArray[RNAArrayLength][2];
    ifstream RNACodonList("Codons.txt");
    readRNACodonTable(RNACodonList, codonArray);
    // Debug: read out the codon list
    for (int i=0; i < RNAArrayLength; i++){
        cout << codonArray[i][0] << " " << codonArray[i][1] << endl;
    }

    return 0;
}


