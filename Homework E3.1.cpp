/*
Name: James Ma
Professor: Tong Yi
Date: Feburary 8th, 2025
Write a program that reads an integer and prints whether it is negative, zero, or positive.
*/

#include <iostream>

int main(){
    int numb;
    std::cout<<"Enter an integer: "<<std::endl;
    std::cin>>numb;
    if (numb<0){
        std::cout<<"negative ";
    }
    else if(numb>0){
        std::cout<<"positive";
    }
    else if(numb==0){
        std::cout<<"zero";
    }
    return 0;
}