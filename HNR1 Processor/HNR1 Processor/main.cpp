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
// Why are you not setting this based on the number of lines that are actually in the input? Is there
// something magic about 65? If there is, you should mention it here.
const int RNAArrayLength = 65;

typedef string CodonTable_t[RNAArrayLength][2];

// Read each line of an ifstream (up to RNAArrayLength lines) and write
// the first and second words on each line into 2D array "codonArray"
void readRNACodonTable(ifstream &inFile,
                       CodonTable_t codonTable){
    string a, b;
    if (inFile.is_open() &! inFile.eof()){
        for (int i=0; i < RNAArrayLength; i++){
            inFile >> a >> b;
            // name the variables a and b with something meaningful;
            // use constants here and elsewhere instead of 0 and 1, eg kCodonKey and kThingyValue
            codonTable[i][0] = a;
            codonTable[i][1] = b;
        }
    }
}

// Given a 2D array of [codon, abbreviation], sort the array by codon
// (modifies original array and returns nothing)
// Do you have to do this sorting yourself, rather than using a standard library routine?
// Also, have you tested this sort? It works, right?
void sortCodons(CodonTable_t codonTable){
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
        }
    }
}

// Given a string "codon" and an array of codon abbreviations, return
// the corresponding abbreviation for this codon
// This should probably be 'codonFromThingy' or 'thingyFromCodon'
string codonLookup(string codon, CodonTable_t codonTable){
    //cout << "(" << codon << ")";
    for (int i=0; i < RNAArrayLength; i++){
        if (codonTable[i][0] == codon){
            return codonTable[i][1];
        }
    }
    return "Invalid Codon"; // this should be a constant too
    // Weirdly, there doesn't seem to be any place you check for that.
    // A more conventional signature for this method would be
    // bool codonLookup(CodonTable_t codonTable, const string& codonKey, string& value);
    // But this is OK too
}

// Given a string, swap any T characters with U
// There is a standard library method or global function on string that replaces substrings, I'm very sure
string DNAtoRNA(string DNA){
    for (int c=0; c < DNA.length(); c++){
        if (DNA[c] == 'T'){
            DNA[c] = 'U';
        }
    }
    return DNA;
}

// Given two seqences, prints the position and base of each codon difference
void difference(string sequenceA,
                string sequenceB,
                CodonTable_t codonTable){
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
void debugReadArray(CodonTable_t codonArray){
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
    // Another sort of ideosyncratic failure reporting technique
    return "File read failure";
    
    // I think I'd have this function look more like:
    // bool loadSequence(ifstream &file, string& sequence);
}

// It does look a lot like there's a latent class, CordonTable, with methods
// like .read(), .sort(), .lookUp(const string& key), and .difference(Sequence, Sequence)

int main() {
    CodonTable_t codonArray;
    ifstream RNACodonList("Codons.txt");
    readRNACodonTable(RNACodonList, codonArray);
    // Sort codon array alphabetically
    sortCodons(codonArray);

    ifstream chickenFile("ChickenHNR1.txt");
    ifstream humanFile("HumanHNR1.txt");
    ifstream chimpFile("ChimpanzeeHNR1.txt");
    // Build strings out of files
    // Here's where a lot of guys would be checking the failure return code that you don't have
    string chickenSequence = loadSequence(chickenFile);
    string humanSequence = loadSequence(humanFile);
    string chimpSequence = loadSequence(chimpFile);

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


