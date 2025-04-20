/* 
student: James Ma
prof: Tong Yi
date: 3-5-25
*/

#include <iostream>
#include <cctype>

int main(){

    std::string name;
    std::cout<<"Input: ";
    std::getline(std::cin,name); //gets the string from the user
    
    for(int i=0;i<name.length();i++){
        std::cout<<name[i]<<" "<<(int)name[i]<<std::endl;//prints out the   ascii value of the string
    }
    
    return 0;
}