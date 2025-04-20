/* 
Name: James Ma
Profession: Tong Yi
Date: 3-6-25
*/

#include <iostream>
#include <string>
#include <iomanip>

int tempo(char rshift){ //converts the char value to an ascii value so it can fit the shiftchar function's functionality
    if(isupper(rshift)){
        return rshift-'A';
    }else
        return rshift-'a';
}

char shiftChar(char c, int rshift){
    if(isalpha(c)){
        if(isupper(c)){
            return 'A'+(c-'A'+ rshift)%26; //converts character into its ascii value
        }else{
            return 'a'+(c-'a'+rshift)%26; //likewise  but for lowercase -- Both convert to A and shift according to how many shifts. say c is Z, it would make C = 26 n wrap the function
        }
    }
    return c;
}

char shiftChar(char c, char j){
    return shiftChar(c,tempo(j));
}

std::string encryptCaesar(std::string plaintext, int rshift){
    for(int i=0;i<plaintext.length();i++){
        plaintext[i]=shiftChar(plaintext[i],rshift);
    }
    return plaintext;
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
char reverseChar(char letter, int shift){ //reverses the function according to shift
    if(isupper(letter)){ //if shift is <their respective A's, it adds 26 to wrap around the alphabet
        letter='A'+(letter-'A'-shift);
        if(letter<65){
            letter+=26;
        }
    }else{
        letter='a'+(letter-'a'-shift);
        if(letter<97){
            letter+=26;
        }
    }
    return letter;
}
std::string decryptCaesar(std::string cipher, int shift){
    for(int i =0;i<cipher.length();++i){
        if(isalpha(cipher[i])){
            cipher[i]=reverseChar(cipher[i],shift);
        }
    }
    return cipher;
}
std::string decryptVigenere(std::string cipher, std::string keyword){
    int j=0;
    for(int i =0;i<cipher.length();++i){
        if(isalpha(cipher[i])){
            cipher[i]=reverseChar(cipher[i],tempo(keyword[j%keyword.length()])); //makes a call to reversechar 
            //tempo(keyword[j%keyword.length()] converts char to int and puts that int as the shift number for the reverse fucnt              
            j++;
        }
    }
    return cipher;
}
int main(){
    std::string plaintext,keyword;
    int shift;
    std::cout<<"Enter plaintext: ";
    std::getline(std::cin,plaintext);
    std::cout<<std::left<<"Enter shift: ";
    std::cin>>shift;
    std::cout<<"Ciphertext: "<<encryptCaesar(plaintext,shift)<<"\n"<<"Decrypted: "<<decryptCaesar(encryptCaesar(plaintext,shift),shift)<<std::endl;
    std::cout<<"Enter keyword: ";
    std::cin>>keyword;
    std::cout<<"Ciphertext: "<<encryptVigenere(plaintext,keyword)<<"\n"<<"Decrypted: "<<decryptVigenere(encryptVigenere(plaintext,keyword),keyword)<<std::endl;

    return 0;
}

//code is so bulky i fix later >.<