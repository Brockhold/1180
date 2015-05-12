//#include <iostream>
//using namespace std;





// Part 3
#include <iostream>
using namespace std;

// only prints, does not return anything
void readData(int n, int numb1[], int numb2[]){
    for (int i=0; i < n; i++){
        cin >> numb1[i] >> numb2[i];
        cout << numb1[i] << " " << numb2[i] << endl;
    }
}

void makeNewArray(int k, int firstArr[], int secondArr[], int thirdArr[]){
    for (int i = 0; i < k; i++){
        if (firstArr[i] > secondArr[i]){
            thirdArr[i] = 100;
        } else {
            thirdArr[i] = 0;
        }
    }
}

int main(){
    void readData(int, int[], int[]);
    void makeNewArray(int, int[], int[], int[]);
    
    int m;
    cin >> m;
    int maxSize = 50;
    int x[maxSize], y[maxSize], z[maxSize];
    readData(m, x, y);
    makeNewArray(m, x, y, z);
    for (int i = 0; i < m; i++){
        cout << z[i] << endl;
    }
    return 0;
}











/*
// problem 7 (bubblsort)
void sortvals(int secondArray[], int k){
    bool swapped = true;
    
}

int main(){
    int list[5]{12,6,-3,7,10};
    sortvals(list,5);
    
    
    
    return 0;
}
*/



/*
// problem #4
int main(){
    // Part A
    int pos;
    string mystring;
    getline(cin,mystring);
    pos = mystring.find(" ");
    string first = mystring.substr(0,pos);
    cout << first << endl;
    
    // Part B
    string username = "qwertyuiop";
    username.erase(3,5);
    username.insert(3,"time");
    cout << "username " << username << endl;
    
    // Part C
    string msg = " tom toms";
    string str = "pelicans";
    
    cout << "XY"+str+"AB" << endl;
    cout << msg.length() << endl;
    str.erase(2,4);
    cout << str << endl;
    
    return 0;
}
*/


/*
 // Test code for problem #3
class personal_c{
public:
    string name = "Henrik Orr";
    int age = 27;
};

class competetive_c{
public: string lastCompetition = "2014 Winter Olympics";
    int score[2]{1,2};
};


class skater_c{
public:
    personal_c personal;
    competetive_c competetive;
    
};

int main() {
    skater_c newSkater;
    if (newSkater.competetive.score[1] < newSkater.competetive.score[0]){
        cout << "woo hoo" << endl;
        cout << newSkater.personal.name << ' ' << newSkater.competetive.score[1];
    } else {
        cout << newSkater.competetive.lastCompetition << " " << newSkater.personal.age;
    }
    return 0;
}
*/