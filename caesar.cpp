/* 
student: James Ma
prof: Tong Yi
date: 3-5-25
*/

#include <iostream>
#include <cctype>

// A helper function to shift one character by rshift
char shiftChar(char c, int rshift){
    if(isalpha(c)){
        if(isupper(c)){
            return 'A'+(c-'A'+rshift)%26; //converts character into its ascii value
        }else{
            return 'a'+(c-'a'+rshift)%26; //likewise  but for lowercase -- Both convert to A and shift according to how many shifts. say c is Z, it would make C = 26 n wrap the function
        }
    }
    return c;
}

// Caesar cipher encryption
std::string encryptCaesar(std::string plaintext, int rshift){
    for(int i=0;i<plaintext.length();i++){
        plaintext[i]=shiftChar(plaintext[i],rshift);
    }
    return plaintext;
}

int main(){
    std::string name;
    std::cout<<"Input: ";
    std::getline(std::cin,name); //gets the string from the user
    int rshift;
    std::cout<<"Shift: ";
    std::cin>>rshift;
    std::cout<<encryptCaesar(name,rshift)<<std::endl;
    return 0;
}