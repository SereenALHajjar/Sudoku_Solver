#pragma once
#include <raylib.h>
#include <iostream>

class Grid
{
public:
    Grid();
    void draw();
    void update(int row, int column, int num, Color color);

private:
    int cellSize;
    int rows;
    int cols;
};