/*
 Name : File and cout writing function testing
 Author: Ben Rockhold
 Description: A set of functions to facilitate writing programs that will send all output to both cout and a file.
    Meant to be easily readable, and if not optimal then at least simple.
 */

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

int append_file(string to_write, string filename){
    ofstream file(filename, ios::app);
    if(file.is_open()){
        file << to_write;
    } else {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void dual_output(string output, string filename, bool from_cin){
    append_file(output,filename);
    if(!from_cin){
       cout << output;
    }
}


int main(int argc, const char * argv[]) {
    string foo = "foo ";
    string bar = "bar ";
    int a = 50;
    float b = 100.0;
    double c = 3.1415;
    
    ostringstream output;
    output << bar << a << b << c;
    dual_output(output.str(), "foo.txt", 0);
//    cout << foo;
    return EXIT_SUCCESS;
}
