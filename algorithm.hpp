#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "grid.hpp"


class Algorithm
{
    public :
        Algorithm() ;
        void setBoard(int board[9][9]);
        bool possible(int row, int col, int num);
        void run(int row, int col);
        bool complete();
        int solution[9][9] ;

    private :
    int board[9][9] ;
};