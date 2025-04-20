/* 
Name: James Ma
Professor: Tong yi
Date: 3-4-25

program reads a file and prints out the lines that have duplicate words
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip> 
#include <sstream>

std::ifstream openFile(){ //prompt the user to open a file
    std::string fileName;
    std::cout<<"Enter file name: ";
    std::cin>>fileName;
    std::ifstream file(fileName);
    if(file.fail()){
        std::cerr<<"File can not be openned";
        exit(1);
    }
    return file;
}

bool repeatCheck(std::string line){
    std::istringstream fin;
    fin.str(line);
    std::string prevword ="";
    std::string word;
    while(fin>>word){
        if(word==prevword)
            return true;
        prevword= word;
    }
    return false;
}

int main(){
    std::ifstream open = openFile();
    int linenum =1;
    std::string textline;
    while(std::getline(open,textline)){
        if(repeatCheck(textline) == true){
            std::cout<<std::setw(7)<<linenum<<":"<<textline<<std::endl;
        }
        linenum++;
    }
    return 0;
}