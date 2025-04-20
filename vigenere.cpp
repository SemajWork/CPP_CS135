/* 
Student: James Ma
Professor: Tong Yi
Date: 3-6-25
*/

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

int tempo(char rshift){ //converts the char value to an ascii value so it can fit the shiftchar function's functionality
    if(isupper(rshift)){
        return rshift-'A';
    }else
        return rshift-'a';
}

char shiftChar(char c, char rshift){
    if(isalpha(c)){
        if(isupper(c)){
            return 'A'+(c-'A'+tempo(rshift))%26; //converts character into its ascii value
        }else{
            return 'a'+(c-'a'+tempo(rshift))%26; //likewise  but for lowercase -- Both convert to A and shift according to how many shifts. say c is Z, it would make C = 26 n wrap the function
        }
    }
    return c;
}

std::string encryptVigenere(std::string plaintext, std::string keyword){
    int j =0;
    for(int i= 0;i<plaintext.length();i++){
        if(isalpha(plaintext[i])){//checks if the char is alphabetic
            plaintext[i]=shiftChar(plaintext[i],keyword[j%keyword.length()]);
            //if it's alphabetic, it will call the shiftchar var to shift according to the ascii value of the current selected value of the keyword
            j++;
            //adds 1 to j to parse through the keyword s.t the keyword will reset everytime it hits 4 and go back to first index
        }
    }
    return plaintext;
}

int main(){
    std::string plaintext,keyword;
    std::cout<<std::setw(20)<<"Enter plaintext: ";
    std::getline(std::cin,plaintext);
    std::cout<<std::setw(20)<<"Enter keyword: ";
    std::getline(std::cin,keyword);
    std::cout<<std::setw(20)<<"Ciphertext: "<<encryptVigenere(plaintext,keyword)<<std::endl;

    return 0;
}

/* 
first step would be getting input of the keyword and the string
next pass it through to the encryptVigenere function

*/