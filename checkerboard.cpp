/*
Name: James Ma
Professor: Tong Yi
Date: Feburary 19th, 2025
Asks user for height and width and prints out checkered pattern rectangle
*/
#include <iostream>
#include <string>

using namespace std;

int main(){
    int width, height; // initializes the height and width
    cout<<"Enter width: ";
    cin>>width;
    cout<<"Enter height: ";
    cin>>height; 

    cout<<"\nShape: "<<endl;
    //prints out the shape line by line
    for(int i =0;i<height;i++){
        for(int j =0;j<width;j++){
            //alternates between the row patterns
            if(i%2==0){
                if(j%2==0){
                    cout<<"*";
                }else{
                    cout<<" ";
                }
            }else if(i%2==1){
                if(j%2==0){
                    cout<<" ";
                }else{
                    cout<<"*";
                }
            }
        }
        cout<<"\n";
    }
    return 0;
}