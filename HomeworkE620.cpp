/* 
Name: James
Professor: Tong Yi

Merges two sorted vectors producing a new sorted vector
*/
#include <iostream>
#include <vector>

std::vector<int> merge_sorted(std::vector<int> a, std::vector<int> b){
    int apointer=0; int bpointer=0; //these will keep track of the index position for each respective array
    std::vector<int> mergedvector;

    while(apointer<a.size() && bpointer<b.size()){ //as long as the new vector is less than the size of the combination of the two vectors continue
        if(a[apointer]<=b[bpointer]) //if the current index in vector a is than the one in vector b, add to vector
            mergedvector.push_back(a[apointer++]);
        else //likewise
            mergedvector.push_back(b[bpointer++]);
    }

    mergedvector.insert(mergedvector.end(),a.begin()+apointer,a.end());
    mergedvector.insert(mergedvector.end(),b.begin()+bpointer,b.end());
    
    return mergedvector;
}

int main(){
    std::vector<int> a = {1,2,3,4,5,5,5,123};
    std::vector<int> b={43,52,123};

    std::vector<int> newlysorted = merge_sorted(a,b);
    
    for(int i : newlysorted)
        std::cout<<i<<std::endl;

    return 0;
}

