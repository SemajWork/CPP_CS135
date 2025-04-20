/*
Name: James Ma
Professor: Tong Yi
Date: Feburary 19th, 2025
Asks user for length and prints out  top right half of a square
*/

#include <iostream>

using namespace std;

int main(){
    cout<<"Input side length: ";
    int length; // initializes length
    cin >> length;
    cout<<"Shape:"<<endl;
    for(int i=1;i<=length;i++){
        for(int j = 1; j<=length;j++){
            if(i>j) //if i is greater than j at any point it would print out the white space needed
                cout<<" ";
            else // since the amount of white space increases by 1 per line, and i increases by 1 per iteration, it would print out 1 white space per iteration of the main for loop
                cout<<"*";
        }
        cout<<"\n";
    }
}