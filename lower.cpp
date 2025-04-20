/*
Name: James Ma
Professor: Tong Yi
Date: Feburary 19th, 2025
Asks user for size and prints bottom left half of a square
*/

#include <iostream>

using namespace std;

int main(){
    int size;
    cout<<"Input side length: ";
    cin>>size;// stores user input value into size

    cout<<"Shape: \n";
    for(int i=1;i<=size;i++){ //iterates through nested forloop until it reaches the length the user input
        for(int j = i;j>0;j--){ //prints # of asteriks according to count i
            cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}