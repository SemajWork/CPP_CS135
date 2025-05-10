#ifndef BOARD_H
#define BOARD_H
#include <vector>
class Board {
//private:
public: //TODO: for gradescope test purpose only
    int numBins; //number of bins
    int capacity; //maximum number of shapes held in each bin
    //need to compile using -std=c++11
    //if using std::vector<std::vector<int>>, otherwise
    //need to use std::vector<std::vector<int> >
    std::vector<std::vector<int> > grid;
    //If not using c++11, need to have space between the last two > >
    //std::vector<std::vector<int> > grid;

    //cannot write as 
    //std::vector<int> grid(numBins, capacity);
    //which results in a one-dimensional array
    //of numBins elements, each element equals capacity.

    int winInHorizontal(int bin); //set as private method to mask details from users
    int winInVertical(int bin);
    int winInDiagonal(int bin);
public:
    Board(); //6 bins, each bin holds at most 4 balls
    Board(int numBins, int capacity); //numBins, each bin holds at most capacity many shapes
    void display() const;
    int add(int player);
        //Given a player,
        //return which bin the player is add a shape

    void play();
    
    int win(int bin); //column must be the most recent ball in that bin
};
#endif
