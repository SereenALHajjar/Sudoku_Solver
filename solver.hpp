
#include "algorithm.hpp"
#include "grid.hpp"



class Solver
{
public:
    Solver();
    void solve();
    void draw();
    void getSudokuBoard();
    std::vector<std::pair<int, int>> numberPos;
    std::vector<std::pair<int, int>> emptyPos;
    std::vector<std::pair<int, int>> solPos;

private:
    Grid grid;
    Algorithm algorithm;
    int board[9][9];
    int solution[9][9];
};