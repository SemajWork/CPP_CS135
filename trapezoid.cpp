/*
Name: James Ma
Professor: Tong Yi
Date: Feburary 19th, 2025
Asks user for height and width then prints an upside down trapezoid
*/

#include <iostream>

int main(){
    int height, width; // initializes the variables
    std::cout<<"Input width: ";
    std::cin>>width;
    std::cout<<"Input height: ";
    std::cin>>height;

    double halfWidth = width/2.0;

    if((height-1)>=halfWidth){
        std::cout<<"Impossible shape!";
        exit(1);
    }

    std::cout<<"Shape:"<<std::endl;

    for(int i = 1; i<=height;i++){
        for(int j=1; j<=width;j++){
            if(j<i || j>width-i+1) // it puts an empty space whenever between the 1st to nth spot and nth to last spot
                std::cout<<" ";
            else
                std::cout<<"*"; // puts asterik whenever it isnt the empty space
        }
        std::cout<<"\n";
    }
    return 0;
}