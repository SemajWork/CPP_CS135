/* 
Name: James Ma
Professor: Tong Yi
*/

#include <iostream>
#include <vector>

//alters a vector such that it only returns positive integers
std::vector<int> goodVibes(const std::vector<int>& v){
    std::vector<int> posvec;//initiates a vector to hold the positive integers
    for(int i : v) {
        if(i>0) //if the element is greater than 0
            posvec.push_back(i);
    }
    return posvec;
}