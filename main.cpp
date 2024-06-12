
#include <raylib.h>
#include "grid.hpp"
#include "solver.hpp"
const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;

double lastUpdate = 0;
bool checkInterval()
{
    if (GetTime() - lastUpdate > 0.4)
    {
        lastUpdate = GetTime();
        return true;
    }
    return false;
}
int main()
{

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT + 100, "Sudoku Solver");
    SetTargetFPS(60);
    Solver solver = Solver();
    bool f = 0;
    int i = 0;
    while (!WindowShouldClose())
    {
        Vector2 mousePosition = GetMousePosition();

        Rectangle solveButton = {SCREEN_WIDTH / 4, SCREEN_HEIGHT - 10, 100, 40};
        bool solveButtonHover = CheckCollisionPointRec(mousePosition, solveButton);
        bool solveButtonPressed = solveButtonHover && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);

        Rectangle clearButton = {SCREEN_WIDTH / 2, SCREEN_HEIGHT - 10, 100, 40};
        bool clearButtonHover = CheckCollisionPointRec(mousePosition, clearButton);
        bool clearButtonPressed = clearButtonHover && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);

        // response to events
        (solveButtonHover) ? DrawRectangleRec(solveButton, DARKGREEN) : DrawRectangleRec(solveButton, GREEN); // Change color when hovering
        (clearButtonHover) ? DrawRectangleRec(clearButton, BROWN) : DrawRectangleRec(clearButton, RED);
        if (solveButtonPressed)
        {
            solver.solve();
            f = 1;
        }
        if (clearButtonPressed)
        {
            solver.solPos.clear();
            f = 0;
            i = 0;
        }

        // Drawing

        BeginDrawing();
        ClearBackground(WHITE);
        solver.draw();
        if (f)
        {
            if (checkInterval())
            {
                solver.solPos.push_back({solver.emptyPos[i].first, solver.emptyPos[i].second});
                i++;
                if (i == solver.emptyPos.size())
                {
                    f = 0;
                }
            }
        }

        DrawText("Solve", solveButton.x + 20, solveButton.y + 10, 20, WHITE);
        DrawText("Clear", clearButton.x + 20, clearButton.y + 10, 20, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}