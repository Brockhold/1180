/*
 Name : Ceasar Cipher
 Author: Ben Rockhold
 Date: 04/20/15
 Description: 
    Asks the user (via cin) for a ceasar cypher offest
    Reads in the file "plaintext.txt"
    Encodes each character of input by rotating it through the alphabet by the offset distance
        (ignores any chracter with an ASCII value outside the inclusive range 32-95)
    Writes the results of the encoding to the file "ciphertext.txt"
*/

#include <fstream>
#include <iostream>
using namespace std;

// Ask the user for an integer between 1 and 95
int getKey(){
    int offsetKey;
    do {
        cout << "Please enter a valid cipher offset (between 1 and 95): ";
        cin >> offsetKey;
        cout << endl;
    } while (1 <= offsetKey && offsetKey <= 95);
    return offsetKey;
}

// Fetches the next char from the input file
char getCharacter(ifstream& inputFile){
    return inputFile.get();
    // this needs to fetch only valid chars (between 32 and 126)
}

void caeserCipher(char input, int cipherOffset, ofstream& outputFile){
    // write return the ASCII value of input, plus the cipher offset, to the outputFile
    
}

// to convert a letter to a number, you can simply subtract 'a' from it;
// a-a = 0
// b-a = 1
// you will also need to convert or ignore capital characters

// cout.width
// cout << right << blah blach blah
// 


int main() {
    ifstream plaintext("plaintext.txt");
    ofstream ciphertext("ciphertext.txt");
    return 0;
}
