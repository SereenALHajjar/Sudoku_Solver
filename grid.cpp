#include "grid.hpp"

Grid::Grid()
{
    this->rows = 9;
    this->cols = 9;
    this->cellSize = 60;
}

void Grid::draw()
{
    float offset = 30;
    for (int i = 0; i <= rows; i++)
    {
        if (i % 3 == 0)
        {
            DrawLineEx({(float)i * cellSize + offset, offset}, {(float)i * cellSize + offset, (float)9 * cellSize + offset}, 2, BLACK);
            DrawLineEx({offset, (float)i * cellSize + offset}, {(float)9 * cellSize + offset, (float)i * cellSize + offset}, 2, BLACK);
        }
        else
        {
            DrawLine(i * cellSize + offset, offset, i * cellSize + offset, 9 * cellSize + offset, GRAY);
            DrawLine(offset, i * cellSize + offset, 9 * cellSize + offset, i * cellSize + offset, GRAY);
        }
    }
}

void Grid::update(int row, int col, int num, Color color)
{
    DrawText(TextFormat("%i", num), col * cellSize + 25 + 30, row * cellSize + 20 + 30, 20, color);
}
