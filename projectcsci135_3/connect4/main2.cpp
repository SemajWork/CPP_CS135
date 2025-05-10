#include "Board.hpp"
#include <iostream>
#include <string>
using namespace std;

//compile and link using command
//g++ -std=c++11 Board.cpp main.cpp -o test
//Then run
//./test A 
//or
//./test B

int main(int argc, const char* argv[]) {
    if (argc != 2) {
       cout << "Need add an integer, like A, after ./a.out" << endl;
       return -1;
    }

    switch (*argv[1]) {
        case 'A': 
        {
            Board game;
            game.play();
            break;
        }
        case 'B':
        {
            Board game(7,5);
            game.play();
            break;
        }
    }

    return 0;
}
