/* 
Name: James Ma
Professor: Tong Yi
*/

#include <iostream>
#include <vector>

//alters a vector such that it only returns positive integers
std::vector<int> goodVibes(const std::vector<int> v){
    std::vector<int> posvec;//initiates a vector to hold the positive integers
    for(int i : v) {
        if(i>0) //if the element is greater than 0
            posvec.push_back(i);
    }
    return posvec;
}

//testing 
int main() {
    std::vector<int> v{1, 2, -1, 3, 4, -1, 6};
    std::vector<int> hold = goodVibes(v);

    for (int i : hold) {
        std::cout << i << " ";
    }

    return 0;
}