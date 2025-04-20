/*
Name: James Ma
Professor: Tong Yi
Date: Feburary 19th, 2025
asks user for width and height and prints a checker board with 3x3 sections
*/

#include <iostream>

int main(){
    int width, height,count,count2;
    std::cout<<"Input width: ";
    std::cin>>width;
    std::cout<<"Input height: ";
    std::cin>>height;

    std::cout<<"Shape:"<<std::endl;
    count=1;
    count2=1;
    for(int i =0;i<height;i++){
        for(int j =0;j<width;j++){

            if(count<=3){ //this seperates the pattern into two scenarios: the first being the first 3 rows and the second being the last 3 rows. The pattern prints such that the first 3 should print for the first values
                if(count2<=3)// and the last 3 should print nothing for the first three values 
                    std::cout<<"*";
                else
                    std::cout<<" ";
            }else if(count>=4){
                if(count2<=3)
                    std::cout<<" ";
                else
                    std::cout<<"*";
            }
            if(count2>=6) // this sets the pattern for the two different scenarios such that every 3 there should either be 3 spaces or asteriks. It resets every 6 spaces etc
                count2=1;
            else
                count2 +=1;
        }
        std::cout<<"\n";
        count2=1; //resets count because its a new iteration with a new row
        if(count>=6)
            count=1;
        else
            count +=1;
    }
    return 0;
}