/*
Name: James Ma
Professor: Tong Yi
Date: Feburary 19th, 2025
asks user for size and prints an x pattern according to size
*/
#include <iostream>
#include <string>

using namespace std;

int main(){
    int size;
    cout<<"Input size: ";
    cin>>size;
    cout<<"Shape: "<<endl;

    for(int i =1; i<=size;i++){ // starts from the first row
        for(int j =1;j<=size;j++){//iterates through the columns of the first row
            if(j==i || j==(size+1-i))//i.e if i was 3, it would mean you would want to only the first element in the 3rd column and if the number was 8, it would only want to print in the 3rd to last hence, the 6th column
                cout<<"*"; //the size + 1 - i gives the exact location of the nth to last column. say its 10, and its 4th column, you would want the 7th post/4th to last 10+1-4 = 7
            else
                cout<<" ";
            
        }
        cout<<"\n";
    }
    return 0;
}
