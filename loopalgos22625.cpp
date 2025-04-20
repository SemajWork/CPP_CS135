#include <iostream>
/* Find the first location of space
character without using find method */
int main(){
    std::cout << "Enter a string: ";
    std::string str;
    std::getline(std::cin, str);
    char target = ' ';
    unsigned int i =0;
    while(str.length()>i && str[i]!=target){
        i++;
    }
    if(str[i]!=target){
        std::cout<<"No space";
    }else
        std::cout<<i;

}