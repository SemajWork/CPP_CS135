/*
Name: James Ma
Professor: Tong Yi
Date: Feburary 19th, 2025
Asks user for height and width and prints out * according to the dimensions entered
*/
#include <iostream>
#include <string>

using namespace std;

int main(){
    int width, height; // initializes the height and width
    cout<<"Enter width: ";
    cin>>width;
    cout<<"Enter height: ";
    cin>>height;

    cout<<"\nShape: "<<endl;
    //prints out the shape line by line
    for(int i =0;i<height;i++){
        for(int j =0;j<width;j++){
            cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}