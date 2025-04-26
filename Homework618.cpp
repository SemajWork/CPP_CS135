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
    int apoint=0;int bpoint=0;
    while(apoint<a.size() && bpoint<b.size()){ //inserts elements from a and b alternatively
        hold.push_back(a[apoint++]);
        hold.push_back(b[bpoint++]);
    }
    //checks if length is smaller than either vector, will then insert the rest of the elements if lenght is less than one of the vector's sizes
    hold.insert(hold.end(),a.begin()+apoint, a.end());
    hold.insert(hold.end(),b.begin()+bpoint,b.end());

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