/* 
Name: James Ma
Professor: Tong Yi
practice recursion lab13
*/

#include <iostream>
#include <ctype.h>

using namespace std;

void printRange(int left, int right){
    if(left>right) //if left is greater than right dont print nun
        return;
    else{ //otherwrint left and recall fuction with left incremeneted 1 
        std::cout<<left<<" ";
        printRange(left+1,right);
    }
}
int sumRange(int left, int right){
    if(left>right)//if left is finally greater than right return 0 and it ends there
        return 0;
    else 
        return left + sumRange(left+1,right); //std::endlessly calls
}
int sumArray(int *arr, int size){
    if(size==0) //if size=0, retur 0 end here
        return 0;
    else    
        return *arr + sumArray(arr+1,size-1); //arr+1 moves onto the next element in the array, and decrements size to keep track # of elements left
}
bool isAlphanumeric(std::string s){
    if(s.empty())
        return true;
    else{
        if(isalnum(s[0]))
            return isAlphanumeric(s.substr(1)); 
    }
    return false;
}
bool nestedParens(std::string s){ //it checks front and back to see if its enclosed parenthese such that () is true, )( is false
    if(s.empty())
        return true;
    else{
        if(s[0]=='(' && s.back()==')')
            return nestedParens(s.substr(1,s.length()-2)); //returns substr of element after 1st string and element before last element in string, you -2 because when you move up 1, you have to minus 1 from length ot anull the inital jump in index, and another 1 to exclude last element
    }
    return false;
}
bool divisible(int *prices, int size){
    return sumArray(prices, size)%2 ==0;
}
int main(){   
    int prices [] = {10, 15, 12, 18, 19, 17, 13, 35, 33};
    int size = sizeof(prices) / sizeof(prices[0]);
    cout<<divisible(prices,size);
}