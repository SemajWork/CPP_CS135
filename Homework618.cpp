/* 
Name: James Ma
Professor: Tong Yi
Date: 4-20-25

writes an array that alternates between 2 vectors appending elements
*/

#include <iostream>
#include <vector>

std::vector<int> append(std::vector<int> a,std::vector<int> b){
    std::vector<int> hold;
    
    hold.insert(hold.end(),a.begin(),a.end());
    hold.insert(hold.end(),b.begin(),b.end());

    return hold;
}

int main(){
    std::vector<int> ab={1, 4, 9, 16};
    std::vector<int> ba={9, 7, 4, 9, 11};

    std::vector<int> abba = append(ab,ba);

    for(int x: abba){
        std::cout<<x<<" ";
    }

    return 0;
}