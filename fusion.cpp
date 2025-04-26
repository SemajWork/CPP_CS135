/* 
Name: James Ma
Professor: Tong Yi

*/

#include <iostream>
#include <vector>

//appends all elements from vetor 2 to 1
void gogeta(std::vector<int> &goku,std::vector<int> &vegeta){
    goku.insert(goku.end(),vegeta.begin(),vegeta.end()); //inserts every element from vegeta into goku
    vegeta.clear(); //clears vegeta
}