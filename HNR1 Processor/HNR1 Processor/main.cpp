/*
 Name : HNR1 Processor
 Author: Ben Rockhold
 Date: 05/5/15
 Description:
    Does stuff with some files.
 */

#include <fstream> // file IO
#include <iostream>
#include <streambuf> // fstream into string
#include <string>
using namespace std;

const int RNAArrayLength = 65;

// Read each line of an ifstream (up to RNAArrayLength lines) and write
// the first and second words on each line into 2D array "codonArray"
void readRNACodonTable(ifstream &inFile,
                       string codonArray[RNAArrayLength][2]){
    string a, b;
    if (inFile.is_open() &! inFile.eof()){
        for (int i=0; i < RNAArrayLength; i++){
            inFile >> a >> b;
            codonArray[i][0] = a;
            codonArray[i][1] = b;
        }
    }
}

// Given a 2D array of [codon, abbreviation], sort the array by codon
// (modifies original array and returns nothing)
void sortCodons(string codonTable[RNAArrayLength][2]){
    
}

// Given a string "codon" and an array of codon abbreviations, return
// the corresponding abbreviation for this codon
string codonLookup(string codon, string codonTable[RNAArrayLength][2]){
    //cout << "(" << codon << ")";
    for (int i=0; i < RNAArrayLength; i++){
        if (codonTable[i][0] == codon){
            return codonTable[i][1];
        }
    }
    return "Invalid Codon";
}

// Given a string, swap any T characters with U
string DNAtoRNA(string DNA){
    for (int c=0; c < DNA.length(); c++){
        if (DNA[c] == 'T'){
            DNA[c] = 'U';
        }
    }
    return DNA;
}

// Given two seqences, prints the position and base of each codon difference
void difference(string sequenceA, string sequenceB, string codonTable[RNAArrayLength][2]){
    if (sequenceA.length() != sequenceB.length()){
        cout << "Length error" << endl;
        return;
    }
    for (int i=0; i < sequenceA.length(); i+=3){
        string subA = DNAtoRNA(sequenceA.substr(i,3));
        string subB = DNAtoRNA(sequenceB.substr(i,3));
        string proteinA  = codonLookup(subA, codonTable);
        string proteinB = codonLookup(subB, codonTable);
        
        if (proteinA != proteinB){
            cout << "Codon difference at position " << i << ":" << endl;
            cout << subA << " = " << proteinA;
            cout << " : ";
            cout << subB << " = " << proteinB;
            cout << endl;
        }
        
    }
    
}

// Debug: read out the codon array
void debugReadArray(string codonArray[RNAArrayLength][2]){
    for (int i=0; i < RNAArrayLength; i++){
        cout << codonArray[i][0] << " " << codonArray[i][1] << endl;
    }
}

// given an ifstream, return a string with the file's contents
string loadSequence(ifstream &file){
    if (file){
        return(string((istreambuf_iterator<char>(file)),
                       istreambuf_iterator<char>()));
    }
    return "File read failure";
}


int main() {
    string codonArray[RNAArrayLength][2];
    ifstream RNACodonList("Codons.txt");
    readRNACodonTable(RNACodonList, codonArray);

    ifstream chickenFile("ChickenHNR1.txt");
    ifstream humanFile("HumanHNR1.txt");
    ifstream chimpFile("ChimpanzeeHNR1.txt");
    // Build strings out of files
    string chickenSequence = loadSequence(chickenFile);
    string humanSequence = loadSequence(humanFile);
    string chimpSequence = loadSequence(chimpFile);
    //debugReadArray(codonArray);
    // Sort codon array
    sortCodons(codonArray);
    //debugReadArray(codonArray);
    
    // Compare chicken and human HNR1 sequences
    cout << endl << "Comparing chicken to human:" << endl;
    difference(chickenSequence, humanSequence, codonArray);
    
    // Compare human and chimp sequences
    cout << endl << "Comparing human to chimp:" << endl;
    difference(humanSequence, chimpSequence, codonArray);
    
    // Compare chicken and chimp sequences
    cout << endl << "Comparing chicken to chimp:" << endl;
    difference(chickenSequence, chimpSequence, codonArray);
    
    
    
    
    return 0;
}


