/*
 Name : HNR1 Processor
 Author: Ben Rockhold
 Date: 05/5/15
 Description:
    A simple program to compare DNA sequences.
    Starts by reading in "codons.txt" for a list of RNA codons, and each 
        codon's associated protein (by abbreviated name). Creates a 2D array
        from the values contained [codon, protein]
    This array is then sorted alphabetically (this is not neccessary).
    Then reads in three files,
        ("ChickenHNR1.txt" "HumanHNR1.txt" "ChimpanzeeHNR1.txt")
        and creates strings representing them.
    Finally, the strings are compared by protein, and if differences are found,
        they are reported. Note that the differences are in proteins, not
        the codon that creates them!
 */

#include <fstream> // file IO
#include <iostream>
#include <streambuf> // fstream into string
#include <string>
using namespace std;


// This value *must* match the number of lines in "codons.txt"
const int RNAArrayLength = 65;

// The codonTable is a list of every codon, and the single-character
// abbreviation of the protein it encoes.
typedef string codonTable_t[RNAArrayLength][2];

// Read each line of an ifstream (up to RNAArrayLength lines) and write
// the first and second words on each line into 2D array "codonArray"
void readRNACodonTable(ifstream &inFile, codonTable_t codonTable){
    string a, b;
    if (inFile.is_open() &! inFile.eof()){
        for (int i=0; i < RNAArrayLength; i++){
            inFile >> a >> b;
            codonTable[i][0] = a;
            codonTable[i][1] = b;
        }
    }
}

// Given a 2D array of [codon, abbreviation], sort the array by codon
// (modifies original array and returns nothing)
void sortCodons(codonTable_t codonTable){
    string previous(codonTable[0][0]), next, temp[2];
    bool ordered = false;
    // Lets try to bubblesort codons alphabetically!
    for (int outer=0;
         outer < RNAArrayLength-1 && ordered == false;
         outer++){
        ordered = true; // If this is not reset by the inner loop, we are done
        for (int inner = 0;
             inner < RNAArrayLength-outer-1;
             inner++){
            if (codonTable[inner][0] > codonTable[inner+1][0]){
                // The current item is greater than the next item, so swap them
                ordered = false;
                // Store the current values in temp
                temp[0] = codonTable[inner][0];
                temp[1] = codonTable[inner][1];
                // Replace the current item with the next item
                codonTable[inner][0] = codonTable[inner+1][0];
                codonTable[inner][1] = codonTable[inner+1][1];
                // Assign the next item the values in temp
                codonTable[inner+1][0] = temp[0];
                codonTable[inner+1][1] = temp[1];
            } // swapping complete
        } // end inner
    } // end outer
}

// Given a string "codon" and an array of codon abbreviations, return
// the corresponding abbreviation for this codon
string codonLookup(string codon, codonTable_t codonTable){
    for (int i=0; i < RNAArrayLength; i++){
        if (codonTable[i][0] == codon){
            return codonTable[i][1];
        }
    }
    return "Invalid Codon"; // bad way to handle this error
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

// Given two seqences, prints the position and base of each protein difference
void difference(string sequenceA, string sequenceB, codonTable_t codonTable){
    if (sequenceA.length() != sequenceB.length()){
        cout << "Length error" << endl;
        return;
    }
    // read both strings in substring bites of 3
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
void debugReadArray(codonTable_t codonTable){
    for (int i=0; i < RNAArrayLength; i++){
        cout << codonTable[i][0] << " " << codonTable[i][1] << endl;
    }
}

// given an ifstream, return a string with the file's contents
string loadSequence(ifstream &file){
    if (file){
        return (string((istreambuf_iterator<char>(file)),
                       istreambuf_iterator<char>()));

    }
    return "File read failure";
}


int main() {
    codonTable_t codonTable;
    ifstream RNACodonList("Codons.txt");
    readRNACodonTable(RNACodonList, codonTable);
    // Sort codon table alphabetically
    sortCodons(codonTable);

    ifstream chickenFile("ChickenHNR1.txt");
    ifstream humanFile("HumanHNR1.txt");
    ifstream chimpFile("ChimpanzeeHNR1.txt");
    // Build strings out of files
    string chickenSequence = loadSequence(chickenFile);
    string humanSequence = loadSequence(humanFile);
    string chimpSequence = loadSequence(chimpFile);
    // Compare chicken and human HNR1 sequences
    cout << endl << "Comparing chicken to human:" << endl;
    difference(chickenSequence, humanSequence, codonTable);
    
    // Compare human and chimp sequences
    cout << endl << "Comparing human to chimp:" << endl;
    difference(humanSequence, chimpSequence, codonTable);
    
    // Compare chicken and chimp sequences
    cout << endl << "Comparing chicken to chimp:" << endl;
    difference(chickenSequence, chimpSequence, codonTable);
    
    return 0;
}


