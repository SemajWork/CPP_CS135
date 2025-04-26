/* 
Name: James Ma
Professor: Tong Yi

*/
#include <iostream>
#include <vector>

//returns a vector populated with integers 0 to n-1
std::vector<int> makeVector(int n){
    std::vector<int> vectint; //initiates the vector
    for(int i=0;i<n;i++) //populates it 
        vectint.push_back(i);

    return vectint;
}