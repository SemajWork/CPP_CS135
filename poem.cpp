/* 
Name: James Ma
Profesor: Tong Yi
*/
#include <iostream>
using namespace std;

string * createAPoemDynamically() {
    //creates dynamically allocated memory *p 
    string *p = new string;
    *p = "Roses are red, violets are blue"; 
    return p;
}

int main() {
    while(true) {
        string *p;
        p = createAPoemDynamically();

        delete p; //deletes the dynamically allocated memory that p points to
        // assume that the poem p is not needed at this point

    }
}