/*
Name: James Ma
Professor: Tong Yi
Date: Feburary 8th, 2025
Write a program that reads three numbers and prints “increasing” if they are in increasing order, “decreasing” if they are in decreasing order, and “neither” otherwise. 
Here, “increasing” means “strictly increasing”, with each value larger than its predecessor. The sequence 3 4 4 would not be considered increasing.
*/

#include <iostream>

int main(){
    int numb[3];

    for(int i=0;i<3;i++){
        std::cout<<"Enter an integer: ";
        std::cin>>numb[i];
    }

    if(numb[0]<numb[1] && numb[1]<numb[2]){
        std::cout<<"increasing ";
    }else if(numb[0]>numb[1] && numb[1]>numb[2]){
        std::cout<<"decreasing";
    }else{
        std::cout<<"neither";
    }

    return 0;
}