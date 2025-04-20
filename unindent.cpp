/* 
student:James Ma
Professor: Tong Yi
*/

#include <iostream>
#include <cctype>

//removes beginning leading spaces
std::string removeLeadingSpaces(std::string line){
    for(int i=0;i<line.size();++i){
        if(!isspace(line[i])){ //parses through array until a character is found
            return line.substr(i); //prints rest of the function 
        }
    }
    return line; // jsut to ensure function has a return value
}

int main(){
    std::string var;
    while(std::getline(std::cin, var)){ //prompts user input infinitely
        std::cout<<removeLeadingSpaces(var)<<std::endl; //removes leading space per
    }

    return 0;
}