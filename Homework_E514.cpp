/* 
Name: James Ma
Professor: Tong Yi
Date: 3-4-25

Write a function void sort2(int& a, int& b) that swaps the values of a and b if a is greater than b and otherwise leaves a and b unchanged. For example,

int u = 2;
int v = 3;
int w = 4;
int x = 1;
sort2(u, v); // u is still 2, v is still 3
sort2(w, x); // w is now 1, x is now 4

Write a function sort3(int& a, int& b, int& c) that swaps its three arguments to arrange them in sorted order. For example,

int v = 3;
int w = 4;
int x = 1;
sort3(v, w, x); // v is now 1, w is now 3, x is now 4
*/

#include <iostream>


void sort2(int& a, int& b){
    if(a>b){
        int store = a;
        a = b;
        b=store;
    }
}
void sort3(int& a, int& b, int& c){
    sort2(a,c);
    sort2(a,b);
    sort2(b,c);
}
int main(){
    
    int num,num2,num3;
    std::cout<<"Enter number: ";
    std::cin>>num;
    std::cout<<"Enter second number: ";
    std::cin>>num2;
    std::cout<<"Enter third number: ";
    std::cin>>num3;

    sort3(num,num2,num3);

    return 0;
}