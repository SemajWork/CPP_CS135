#include <iostream>
#include "Board.hpp"

struct Coord{
    int bin; //bin index of data member grid
    int indx; //index inside the bin
};

Board::Board() {
    numBins =6;
    capacity =4;

    for (int i=0;i<numBins;i++){
        std::vector<int> oneBin;
        grid.push_back(oneBin);
    }
}
Board::Board(int numBins, int capacity){
    
    this->numBins = (numBins>=5) ? numBins : 5; //equals numBins if numbins is greater or equal to 5,otherwise set to 5 if smaller than 5
    this->capacity = (capacity>=4) ? capacity : 4; //likewise, but instead if smaller than 4 it sets it equal to 4

    for(int i =0; i<this->numBins; i++){
        std::vector<int> oneBin;
        grid.push_back(oneBin);
    }
}
void print(int numBins){
    std::cout<< "+";
    for(int i =0;i<numBins;i++)
        std::cout<<"--+";
    
    std::cout<<std::endl;
}
void Board::display() const{
    // map 0 to a red ball \033[31m\u2b24 ,
    // where \033[31m is red and \u2b24 is a ball
    // map 1 to a blue pentagon \033[34m\u2b1f
    // where \033[34m is blue and \u2b1f is a pentagon
    // map 2 to a red double circle \033[31m\u25c9
    // where \u25c9 is a double circle
    // map 3 to a blue empty pentagon \033[34m\u2b54
    // where \u2b54 is a pentagon with edges only
    // \033[0m is black color, the default color
    // For more shapes, see https://jrgraphix.net/r/Unicode/25A0-25FF
    std::string mapping [] = {"\033[31m\u2b24\033[0m",
                            "\033[34m\u2b1f\033[0m" , 
                            "\033[31m\u25c9\033[0m" , 
                            "\033[34m\u2b54\033[0m"};// \033[32 m is green color
    print(numBins);
    for(int j=capacity-1;j>=0;j--){
        std::cout<<"|";
        for (int i = 0; i < numBins; i++) { 
            if (j < grid[i].size()) { //if the element's index is greater than # of elements in the list, print an empty
                std::cout << mapping[grid[i][j]] <<" |";
            } else {
                std::cout <<"  |";
            }
        }
        std::cout<<std::endl;
        print(numBins);
    }
    for(int i=0;i<numBins;i++)
        std::cout<<" "<<i<<" ";
    std::cout<<std::endl;
}
int Board::add(int player) {
    int bindex;//bin index
    while(true){
        std::cout<<"Enter a bin index in [0,"<<numBins<<") that is not full: ";
        std::cin>>bindex;

        if(bindex>=numBins || bindex<0) //if user input isout of range, raise error and reprompt for input
            std::cout<<"Invalid bin index, it needs to be in [0,"<<numBins<<")"<<std::endl;
        else if(grid[bindex].size()>=capacity) //means the bin is full, reprompts
            std::cout<<"This is full"<<std::endl; 
        else{ //will store the profile, and return the index
            grid[bindex].push_back(player);
            return bindex;
        }
            
    }
}

void Board::play(){
    //displays an empty grid
    display();
    //will store which player has won
    int winCondition=-1;
    //this will automatically alternate between which player is being played within the while loop
    int playerChoose=0;
    
    int fullbins=0; //checks # of full bins
    while(winCondition==-1 && fullbins !=numBins){
        fullbins=0;
        for(int i =0;i<numBins;i++){
            if(grid[i].size()==capacity)
                fullbins++;
        }
        winCondition=win(add(playerChoose)); //adds the new index and also stores the index where it was inserted into the var winCondition then checking for a win
        display();
        playerChoose=(playerChoose+1)%2; //alternates between plyr 1 & 0
    }
    
    if(winCondition==0)
        std::cout<<"winner: red";
    else if(winCondition==1)
        std::cout<<"winner: blue";
    else    
        std::cout<<"a tie";
}


int Board::win(int bin){ //column must be the most recent ball in that bin
    int idx = grid[bin].size() -1;
    //find out the player residing at that last index of bin
    int player = grid[bin][idx];
    
    if(winInDiagonal(bin) == player || winInVertical(bin) == player || winInHorizontal(bin) == player)
        return player;

    return -1;
}

int Board::winInDiagonal(int bin){
    //find out last index of bin
    int idx = grid[bin].size() -1;
    //find out the player residing at that last index of bin
    int player = grid[bin][idx];
    //declare candidatess as a vector of Coord
    std::vector<Coord> candidates;
    //candidates saves the location of all horizontal neighbors of the top elements of the given paramter bin
    //that share the same value of that top element, which is saved in player.
    candidates.push_back({bin,idx});

    //checking top left to bottom right diagonal for consecutives
    for(int i =bin-1, j = idx+1; i>=0 && j<capacity;i--, j++){
        if(j>=grid[i].size() || grid[i][j]!=player)
            break;
        candidates.push_back({i,j});
    }
    
    for(int i = bin+1,j=idx-1; i<numBins,j>=0;i++,j--){
        if(j>=grid[i].size() || grid[i][j]!=player)
            break;
        candidates.push_back({i,j});
    }
    //if there is a diagonal 4 in a row, it will return player/indicate a win is found
    if (candidates.size()>=4){
        //change all elements in cnandidates to be player +2
        for(int i=0;i<candidates.size();i++)
            grid[candidates[i].bin][candidates[i].indx]+=2;
        return player;
    }
    candidates.clear();
    candidates.push_back({bin,idx});
    //check bottom left to top right diagonal
    for(int i =bin-1, j = idx-1; i>=0 && j>=0;i--, j--){
        if(j>=grid[i].size() || grid[i][j]!=player)
            break;
        candidates.push_back({i,j});
    }
    //coutn consecutive elements equaling to the right of grid
    for(int i = bin+1,j=idx+1; i<numBins,j<capacity;i++,j++){
        if(j>=grid[i].size() || grid[i][j]!=player)
            break;
        candidates.push_back({i,j});
    }
    if (candidates.size()>=4){
        //change all elements in cnandidates to be player +2
        for(int i=0;i<candidates.size();i++)
            grid[candidates[i].bin][candidates[i].indx]+=2;
        return player;
    }

    return -1;
}

int Board::winInHorizontal(int bin){
    //find out last index of bin
    int idx = grid[bin].size() -1;
    //find out the player residing at that last index of bin
    int player = grid[bin][idx];
    //declare candidatess as a vector of Coord
    std::vector<Coord> candidates;
    //candidates saves the location of all horizontal neighbors of the top elements of the given paramter bin
    //that share the same value of that top element, which is saved in player.
    
    //who can be the first elements of candidates
    candidates.push_back({bin,idx});
    //count consecutive elements equaling player to the left of grid[bin][idx]. save their loc to candidates
    for(int i =bin-1; i>=0;i--){
        if(idx>=grid[i].size() || grid[i][idx]!=player)
            break;
        candidates.push_back({i,idx});
    }
    //coutn consecutive elements equaling to the right of grid
    for(int i=bin+1;i<numBins;i++){
        if(idx>=grid[i].size() || grid[i][idx]!=player)
            break;
        candidates.push_back({i,idx});
    }
    if (candidates.size()>=4){
        //change all elements in cnandidates to be player +2
        for(int i=0;i<candidates.size();i++)
            grid[candidates[i].bin][candidates[i].indx]+=2;
        return player;
    }
    
    return -1;
    
}

int Board::winInVertical(int bin){
    //find out last index of bin
    int idx = grid[bin].size() -1;
    if(grid[bin].size()<4)
        return -1;
    //find out the player residing at that last index of bin
    int player = grid[bin][idx];
    //declare candidatess as a vector of Coord
    std::vector<Coord> candidates;
    
    //candidates saves the location of all vertical neighbors of the top elements of the given paramter bin
    //that share the same value of that top element, which is saved in player.
    
    //who can be the first elements of candidates
    candidates.push_back({bin,idx});
    //count consecutive elements equaling player to the bottom of grid[bin][idx]. save their loc to candidates
    for(int i =idx-1; i>=0;i--){
        if(grid[bin][i]!=player)
            break;
        candidates.push_back({bin,i});
    }
    //coutn consecutive elements equaling to the top of grid
    for(int i=idx+1;i<grid[bin].size();i++){
        if(grid[bin][i]!=player)
            break;
        candidates.push_back({bin,i});
    }
    if (candidates.size()>=4){
        //change all elements in cnandidates to be player +2
        for(int i=0;i<candidates.size();i++)
            grid[candidates[i].bin][candidates[i].indx]+=2;
        return player;
    }

    return -1;
}