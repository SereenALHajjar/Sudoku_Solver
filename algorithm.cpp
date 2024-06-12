#include "algorithm.hpp"

Algorithm::Algorithm()
{
}

void Algorithm::setBoard(int board[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            this->board[i][j] = board[i][j];
        }
    }
}

bool Algorithm::possible(int row, int col, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == num)
            return false;
        if (board[i][col] == num)
            return false;
    }
    row /= 3;
    col /= 3;
    row *= 3;
    col *= 3;
    for (int i = row; i < row + 3; i++)
    {
        for (int j = col; j < col + 3; j++)
        {
            if (board[i][j] == num)
                return false;
        }
    }
    return true;
}

void Algorithm::run(int row, int col)
{
    if (complete() || row == 9)
    {
        for (int i = 0; i < 9; i++)
        {

            for (int j = 0; j < 9; j++)
            {
                this ->solution[i][j] = board[i][j];
               std:: cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
        return;
    }
    if (board[row][col] != 0)
    {
        if (col < 8)
            run(row, col + 1);
        else
            run(row + 1, 0);
        return;
    }
    for (int i = 1; i <= 9; i++)
    {
        if (possible(row, col, i))
        {
            board[row][col] = i;

            if (col < 8)
                run(row, col + 1);
            else
                run(row + 1, 0);

            board[row][col] = 0;
        }
    }
}

bool Algorithm::complete()
{
    std::vector<int> row, col;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            row.push_back(board[i][j]);
            col.push_back(board[j][i]);
        }
        std::sort(row.begin(), row.end());
        std::sort(col.begin(), col.end());
        for (int i = 0; i < 9; i++)
        {
            if (row[i] != i + 1)
                return false;
            if (col[i] != i + 1)
                return false;
        }
        row.clear();
        col.clear();
    }
    return true;
}
