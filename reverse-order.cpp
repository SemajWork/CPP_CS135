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
    string date1,date2,Point_time,time[365];
    cout<<"Enter starting date: ";
    cin>>date1;
    cout<<"Enter ending date: ";
    cin>>date2;
    int test = 0;

    double AUGEVolume, AUGEASTLEVANALOG	,AUGWVOLUME,AUGWESTLEVANALOG,wele[365];
    int count=0;
    while(fin >> Point_time >> AUGEVolume >> AUGEASTLEVANALOG>>	AUGWVOLUME>>AUGWESTLEVANALOG) { 
    // this loop reads the file line-by-line
    // extracting 5 values on each iteration 
    
        fin.ignore(INT_MAX, '\n'); //skips to the end of line, 
                          //ignorring the remaining columns
        if(test==1||Point_time==date1){
            test=1;
            time[count]=Point_time;
            wele[count]=AUGWESTLEVANALOG;
            count++;
        }
        if(Point_time==date2){
            break;
        }     
    }

    for(int i=count-1;i>=0;i--){
        cout<<time[i]<<" "<<wele[i]<<" ft"<<endl;
    }

    return 0;
}   

/* while(fin >> Point_time >> AUGEVolume >> AUGEASTLEVANALOG>>	AUGWVOLUME>>AUGWESTLEVANALOG) { 
        // this loop reads the file line-by-line
        // extracting 5 values on each iteration 
        
            fin.ignore(INT_MAX, '\n');
            if(test==1||Point_time==date1){
                test=1;
                time[count]=Point_time;
                wele[count]=AUGWESTLEVANALOG;
                count++;
            }
            if(Point_time==date2){
                break;
            }
    } */