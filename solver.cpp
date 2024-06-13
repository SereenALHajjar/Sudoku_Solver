
#include "solver.hpp"
#if defined(_WIN32)
#define NOGDI  // All GDI defines and routines
#define NOUSER // All USER defines and routines
#endif

#include "json.hpp"
#include "httplib.h"

#if defined(_WIN32) // raylib uses these names as function parameters
#undef near
#undef far
#endif

Solver::Solver()
{
    int board[9][9] = {
        {0, 0, 0, 8, 3, 0, 0, 5, 7},
        {0, 0, 8, 5, 0, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 2, 0, 8, 0},
        {8, 0, 2, 3, 9, 0, 7, 0, 0},
        {6, 0, 0, 1, 0, 0, 0, 3, 2},
        {0, 5, 7, 2, 0, 4, 0, 9, 0},
        {0, 6, 0, 4, 1, 0, 3, 7, 0},
        {0, 7, 3, 9, 0, 8, 0, 6, 0},
        {0, 0, 0, 7, 6, 0, 4, 0, 0}};
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            this->board[i][j] = board[i][j];
            if (board[i][j] != 0)
                this->numberPos.push_back({i, j});
            else
                this->emptyPos.push_back({i, j});
        }
    }
    this->grid = Grid();
    this->algorithm = Algorithm();
    algorithm.setBoard(board);
    getSudokuBoard();
    // algorithm.run(0, 0) ;
}

void Solver::solve()
{
    algorithm.run(0, 0);
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
    try
    {
    httplib::Client cli("https://sudoku-api.vercel.app");


        auto res = cli.Get("/api/dosuku");

std::cout<<res<<std::endl ;
        // if (res && res->status == 200)
        // {
        //     auto boardJson = nlohmann::json::parse(res->body);
        //     auto grids = boardJson["newboard"]["grids"];
        //     auto board = grids[0]["value"];
        //     std::cout << "Sudoku Board:" << std::endl;
        //     for (const auto &row : board)
        //     {
        //         for (const auto &cell : row)
        //         {
        //             std::cout << cell << " ";
        //         }
        //         std::cout << std::endl;
        //     }
        // }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
