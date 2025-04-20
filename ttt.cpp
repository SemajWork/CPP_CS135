
/*
Name:James Ma
Professor: Tong yi
Date: 2/11/24
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

int main(){
    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
    cerr << "File cannot be opened for reading." << endl;
    exit(1); // exit if failed to open the file
    }

    string junk;        // new string variable
    getline(fin, junk); // read one line from the file
    string date1,date2;
    cout<<"Enter starting date: ";
    cin>>date1;
    cout<<"Enter ending date: ";
    cin>>date2;
    int test = 0;
    string Point_time;
    double AUGEVolume, AUGEASTLEVANALOG	,AUGWVOLUME;
    while(fin >> Point_time >> AUGEVolume >> AUGEASTLEVANALOG>>	AUGWVOLUME) { 
    // this loop reads the file line-by-line
    // extracting 5 values on each iteration 
    
        fin.ignore(INT_MAX, '\n'); //skips to the end of line, 
                          //ignorring the remaining columns
        if(test==1){
            if(AUGEVolume>AUGWVOLUME){
                cout<<Point_time<<" East";
            }else if(AUGEVolume<AUGWVOLUME) {
                cout<<Point_time<<" West";
            }else if(AUGEVolume==AUGWVOLUME) {
                cout<<Point_time<<" Equal";
            }
            if(Point_time==date2){
                test=0;
            }
        }
        else if(Point_time == date1){
            if(AUGEVolume>AUGWVOLUME){
                cout<<Point_time<<" East";
            }else if(AUGEVolume<AUGWVOLUME) {
                cout<<Point_time<<" West";
            }else if(AUGEVolume==AUGWVOLUME) {
                cout<<Point_time<<" Equal";
            }
            test =1;
        }                  
    }
    return 0;
}