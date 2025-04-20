/*
Name: James Ma
Professor: Tong Yi
Date: Feburary 1st, 2025
Write a program that asks the user to input

•The number of gallons of gas in the tank

•The fuel efficiency in miles per gallon

•The price of gas per gallon

Then print the cost per 100 miles and how far the car can go with the gas in the tank.
 */

#include <iostream>

int main(){
    float gallon, mileperg, pricegal, perhund, gasdist;
    std::cout<<"How many gallons of gas do you want in your tank: ";
    std::cin>>gallon;
    std::cout<<"What is the miles per gallon of your car: ";
    std::cin>>mileperg;
    std::cout<<"What is the price per gallon: ";
    std::cin>>pricegal;
    perhund= (100/mileperg)*pricegal;
    gasdist= gallon*mileperg;
    std::cout<<"It costs "<<perhund<<" per hundred miles driven, and with your current amount of gas, you can go "<<gasdist<<" miles.";
    return 0;
}