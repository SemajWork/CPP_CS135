
/*
Name: James ma
Date: Feb 23, 2025
Write a program numbers.cpp that defines a function

*/

#include <iostream>
#include <cmath>
bool isDivisibleBy(int n, int d){ //uses modular to test if n is totally divisble by d
    if(d==0)
        return false;
    else if(n%d==0)
        return true;
    else // if theres remainder it returns false and prompts the on response
        return false;
}

bool isPrime(int n){    
    if(n<=1){//asdg
        return false;
    }
    if(n>=2){
        for(int i=2;i<=(n/2);i++){
            if (n%i==0) 
                return false;
            }
    }
    return true;
}

int nextPrime(int n){
    n+=1;
    if(isPrime(n)==true){
        return n;
    }else{
        while(isPrime(n)!=true){
            n+=1;
            isPrime(n);
        }
    }
    return n;
}

int countPrimes(int a, int b){ //calls prev prime checker and passes through a forloop that counts everytime isPrime returns a true
    int count = 0;
    for(int i =a;i<=b;i++){
        if(isPrime(i)==true){
            count+=1;
        }
    }
    return count;
}
bool isTwinPrime(int n){
    if(isPrime(n)==true&&(isPrime(n-2)==true || isPrime(n+2)==true)){
        return true;
    }
    return false;
}
int nextTwinPrime(int n){ //idk why it says print next greatest twin prime but then says input of 5 should return 5 smfh
    /* if(isTwinPrime(n)==true){
        return n;
    } */
    n=nextPrime(n);
    while(isTwinPrime(n)!=true)
        n=nextPrime(n);
    return n;
}
int largestTwinPrime(int a, int b){ //creates variable max to store nexttwinprime
    if(nextTwinPrime(a)>b){
        return -1;
    }
    
    while(b>=a && isTwinPrime(b)==false){
        b--;
    }
    return b;
}
//hiii
//byeee
int main(){
    int start,end;
    std::cout<<"Enter beginning digit: ";
    std::cin>>start;
    std::cout<<"Enter ending digit: ";
    std::cin>>end;

    std::cout<<largestTwinPrime(start,end);

    return 0;
}