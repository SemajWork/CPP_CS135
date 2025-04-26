/* 
Name: james Ma
Professor: tong yi
*/

#include <iostream>
#include <vector>

//returns a vector with the sum of both vector's corresponding indexes, will just append the rest of a vector if it is longer than the other
std::vector<int> sumPairWise(std::vector<int> &v1, std::vector<int> &v2){
    std::vector<int> pairwise;
    int i=0;
    //populates with sum of each vector's corresponding index
    while(i<v1.size() && i<v2.size()){
        pairwise.push_back(v1[i]+v2[i]);
        i++;
    }

    //adds remaining elements from either vector 
    pairwise.insert(pairwise.end(),v1.begin()+i,v1.end()); 
    pairwise.insert(pairwise.end(),v2.begin()+i,v2.end());

    return pairwise;
}