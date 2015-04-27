/*
 Name : Ceasar Cipher
 Author: Ben Rockhold
 Date: 04/20/15
 Description: 
    Asks the user (via cin) for a ceasar cypher offset value.
    Reads in the file "plaintext.txt" and encodes each character of input 
    by rotating it through the alphabet by the offset value.
    (ignores any chracter with an ASCII value outside the inclusive range 32-95)
    Writes the results of the encoding to the file "ciphertext.txt"
*/

#include <fstream>
#include <iostream>
using namespace std;

// Writes rather verbose information about what was converted and why
const int debug_messages = false;

// Ask the user for an integer between 1 and 95
int getKey(){
    int offsetKey;
    do {
        cout << "Please enter a valid cipher offset (between 1 and 95): ";
        cin >> offsetKey;
        cout << endl;
    } while (1 > offsetKey || offsetKey > 95);
    return offsetKey;
}

// Fetches the next valid char from the input file
char getCharacter(ifstream& inputFile){
    char nextChar;
    inputFile.get(nextChar);
    // Filter non-ASCII chars
    if (nextChar < 32 || nextChar > 126){
        if (debug_messages){
            cout << "    Invalid ASCII" << " : " << (int)nextChar << endl;
        }
        return 0; // return a null, filtered later
    }
    return nextChar;
    // this needs to fetch only valid chars (between 32 and 126)
}

// Encipher each input char with the cipherOffset, and write to outputFile
void caeserCipher(char input, int cipherOffset, ofstream& outputFile){
    // filter null characters
    if (input != 0){
        // Write each character and its ASCII integer to console for debugging
        if (debug_messages) cout << input << " : " << (int)input;
        // Add offset to the input char, if result > 126, wrap it back to 32
        int outputChar = (int)input + cipherOffset;
        if (debug_messages) cout << "\t-O> " << (int)outputChar;
        if (outputChar > 126){
            outputChar = outputChar - 95;
            if (debug_messages) cout << "\t-W> " << (int)outputChar;
        }
        if (debug_messages) cout << "\t : " << (char)outputChar << endl;
        //cout << outputChar << " : " << (int)outputChar << endl << endl;
        outputFile << (char)outputChar;
    }
}

// The reverse of the above
char deCaeserCipher(char input, int cipherOffset){
    char outputChar = (int)input - cipherOffset;
    if (outputChar < 32) outputChar = outputChar + 95;
    if (debug_messages) cout << outputChar;
    return outputChar;
}


// Given an offset and a cipherFile, produces the file decodedMessage
void crack(int offset, ifstream& cipherFile, ofstream& decodedMessage){
    cipherFile.clear();
    // eof continues to be false
    cipherFile.seekg(0, ios::beg);
    decodedMessage << "Deciphered with offset " << offset << endl;
    while(!cipherFile.eof()){
        char decodedChar = deCaeserCipher(getCharacter(cipherFile), offset);
        cout << decodedChar;
        decodedMessage << decodedChar;
    }
    decodedMessage << endl;
}

int confirmCrack(){
    cout << endl << "Is the mesage cracked? (y/N)" << endl;
    string reponse;
    cin >> reponse;
    cout << endl;
    if (reponse == "Y" || reponse == "y"){
        return 1;
    }
    return 0;
}

// Calls crack* with offset equal to every value in the range lower-upper
void crackCaesarsCipher(int lowerLimit,
                        int upperLimit,
                        ifstream& cipherFile,
                        ofstream& decodedMessage){
    int offset = lowerLimit;
    bool crackedYet = 0;
    // If it's not cracked yet, continue
    while(!crackedYet && offset <= upperLimit){
        cout << "Attempting to decode with offset " << offset << ":" << endl;
        crack(offset, cipherFile, decodedMessage);
        offset += 1;
        crackedYet = confirmCrack();
        if (crackedYet){
            cout << "Cracking complete!"<<endl;
            decodedMessage << "User confirms success for offset "<< offset;
        }
    }
}



/*
 Part I:
    First performs encoding of plaintext.txt into ciphertext.txt
 Part II:
    Attempts to break the cipher on secretMessage.txt
        uses every offset specified by user in the range lower-upper
    Stops after each attempt to ask the user to confirm if the crack succeeded
*/
int main() {
    ifstream plaintext("plaintext.txt");
    ofstream ciphertext("ciphertext.txt");
    int offset = getKey();
    while(!plaintext.eof()){
        caeserCipher(getCharacter(plaintext),offset,ciphertext);
    }
    plaintext.close();
    ciphertext.close();
    cout << "Complete; results written to ciphertext.txt" << endl;
    if (debug_messages){
        cout << "Deciphered results:" << endl << endl;
        ifstream deciphertext("ciphertext.txt");
        deciphertext.clear();
        while(!deciphertext.eof()){
            deCaeserCipher(getCharacter(deciphertext),offset);
        }
    }
    int upper, lower;
    ifstream secretMessage("secretMessage.txt");
    ofstream decodedMessage("decodedMessage.txt");
    cout << endl << "Attempting to crack secretMessage.txt" << endl;
    cout << "Please enter a value for the offset to start from: ";
    cin >> lower;
    cout << endl << "Now enter the value for the upper limit for the offset: ";
    cin >> upper;
    cout << endl;
    crackCaesarsCipher(lower, upper, secretMessage, decodedMessage);
    return 0;
}


// to convert a letter to a number, you can simply subtract 'a' from it;
// a-a = 0
// b-a = 1
// you will also need to convert or ignore capital characters

// cout.width
// cout << right << blah blach blah
//
