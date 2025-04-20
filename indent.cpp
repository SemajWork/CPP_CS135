/*
Author: James Ma
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab 7b

Correctly indents user input code according to # of brackets
*/
#include <iostream>
#include <cctype>
#include <string>
#include <vector>

std::string removeLeadingSpaces(std::string line){
    for(int i=0;i<line.size();++i){
        if(!isspace(line[i])){ //parses through array until a character is found
            return line.substr(i); //prints rest of the function 
        }
    }
    return line; // jsut to ensure function has a return value
}

std::string tab(int len){
    std::string tab;
    for(int i =0;i<len;++i){
        tab+="\t";
    }
    return tab;
}

int countChar(std::string line, char c);

int main(){
    std::string var;
    std::vector<std::string> hold;

    while(std::getline(std::cin,var)){
        hold.push_back(removeLeadingSpaces(var));
    }
    hold.shrink_to_fit();
    return 0;
}