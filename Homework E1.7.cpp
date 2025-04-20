/*
Name: James Ma
Professor: Tong Yi
Date: Feburary 1st, 2025
Program allows three names from console and prints them all on one line
Enter three names from console, then print each of them, one in a line.
*/

#include <iostream>
#include <string>

int main(){
    std::string name1,name2,name3;
    std::cout<<"Enter first name: ";
    std::cin>>name1;
    std::cout<<"Enter second name: ";
    std::cin>>name2;
    std::cout<<"Enter third name: ";
    std::cin>>name3;
    std::cout<<name1<<std::endl;
    std::cout<<name2<<std::endl;
    std::cout<<name3<<std::endl;
    return 0;
}