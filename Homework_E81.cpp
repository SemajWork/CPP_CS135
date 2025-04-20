/* 
student: james ma
Prof: Tong Yi
opens text file inputs text closes then reopens and prints the string
*/

#include <iostream>
#include <fstream>

int main(){
    std::ofstream file("hello.txt");//inputs
    if(file.is_open()){
        file << "Hello, World!";
    }
    file.close();
    std::ifstream fin("hello.txt");

    if(fin.is_open()){  //checks if file is reopened
        std::string line;
        while(std::getline(fin,line))
            std::cout<<line;
    }//prints otu all

    return 0;
}