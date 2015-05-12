/*
 
 
 
*/

#include <iostream>
using namespace std;


int main(int argc, const char * argv[]) {
    int i;
    for (i = 0; i <= 20; i++){
        cout << i;
        switch (i%5) {
            case 1:
                cout << " is a case!" << endl;
                break;
            case 2:
                cout << " nyaa";
            case 3:
                cout << " woo";
            case 4:
                cout << endl;
                break;
            default:
                cout << " default case :(" << endl;
                break;
        }
    }
    cout << endl;
    int array_length = 5;
    int large_array[array_length];
    for (int x = 0; x <= array_length; x++){
        large_array[x] = x * x;
        //cout << large_array[x] << endl;
    }
    int sum = 0;
    cout << sum;
    for (int y = 0; y <= array_length; y++){
        cout << " + " << large_array[y];
        sum += large_array[y];
    }
    cout << " = " << sum << endl;
    
}
