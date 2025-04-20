/*
Name: James Ma
Professor: Tong Yi
Date: Feburary 8th, 2025
Write a program that reads a word and prints each character of the word on a separate line. For example, if the user provides the input "Harry", the program prints
*/

#include <iostream>
using namespace std;

int main(){
    string name;
    cout<<"Enter a name: ";
    getline(cin, name);

    for(int i = 0; i<name.length();i++){
        cout<<name[i]<<endl;
    }
    
    return 0;
}