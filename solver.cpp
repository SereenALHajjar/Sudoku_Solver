
#include "solver.hpp"

#include "json.hpp"

#include <fstream>

Solver::Solver()
{
    init();
    this->grid = Grid();
    this->algorithm = Algorithm();
    // algorithm.run(0, 0) ;
}

void Solver::init()
{
    getSudokuBoard();
    this->numberPos.clear();
    this->emptyPos.clear();
    this->solPos.clear();
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {

            if (board[i][j] != 0)
                this->numberPos.push_back({i, j});
            else
                this->emptyPos.push_back({i, j});
        }
    }

}
void Solver::solve()
{
    algorithm.setBoard(board);
    int found =0 ;
    algorithm.run(0, 0 , found);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            this->solution[i][j] = algorithm.solution[i][j];
        }
    }
}

void Solver::draw()
{
    grid.draw();
    for (int i = 0; i < numberPos.size(); i++)
    {
        int row = numberPos[i].first;
        int col = numberPos[i].second;
        grid.update(row, col, this->board[row][col], BLACK);
    }
    for (int i = 0; i < solPos.size(); i++)
    {
        int row = solPos[i].first;
        int col = solPos[i].second;
        grid.update(row, col, this->solution[row][col], BLUE);
    }
}

void Solver::getSudokuBoard()
{
    std::string file_path = "..\\..\\sudoku_boards\\Data.json";
    std::ifstream file(file_path);
    if (!file.is_open())
    {
        std::cerr << "Could not open the file!" << std::endl;
        // return 1;
    }
    nlohmann::json sudoku_data;
    file >> sudoku_data;
    int random = rand() % sudoku_data.size();
    auto board = sudoku_data[random]["value"];
    int i = 0, j = 0;
    for (const auto &row : board)
    {
        j = 0;
        for (const auto &cell : row)
        {
            this->board[i][j] = cell;
            j++;
            if (j == 9)
                break;
            // std::cout << cell << std::endl;
        }
        // std::cout << std::endl;
        i++;
        if (i == 9)
            break;
    }
    // std::cout << "-------------------" << std::endl;
}

