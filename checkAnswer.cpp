/*
Name: James Ma
Professor: Tong Yi
Date: Feburary 8th, 2025
Asks the user two questions and returns true or false depending on their answer
*/

#include <iostream>
using namespace std;

int main(){
    string ans,ans2;
    bool boolean_expression;

    cout<<"\nWhat is -1 + 5 / 3 ? ";
    getline(cin,ans);
    boolean_expression = ans=="0";
    cout << boolalpha << boolean_expression;

    cout<<"\nAssume that n is properly declared and initialized.Write a condition to represent that n does NOT satisify 0 < n < 100 ";
    getline(cin,ans2);
    boolean_expression = ans2 =="(n <= 0 || n >= 100)";
    cout << boolalpha << boolean_expression;
    
    return 0;
}