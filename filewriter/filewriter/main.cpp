//
//  main.cpp
//  filewriter
//
//  Created by Ben Rockhold on 2/10/15.
//  Copyright (c) 2015 Ben Rockhold. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;


int main(int argc, const char * argv[]) {
    ofstream outfile;
    outfile.open("output.txt");
    outfile << "==Header==";
    cout << "Type stuff\n";
    string first, last;
    cin >> first, last;
    outfile << "First: " << first << " Last: " << last << endl;
    outfile.close();
    
    return 0;
}
