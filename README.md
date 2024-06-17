# Sudoku Solver

This project is a Sudoku solver implemented in C++ using the Raylib library for the graphical user interface (GUI). The solver can automatically solve Sudoku puzzles and display the solution interactively.

## Features

- Load Sudoku puzzles from a JSON file.
- Display Sudoku puzzles in a graphical interface.
- Solve puzzles step-by-step or automatically.
- User-friendly interface built with Raylib.
- Support for 50 easy Sudoku puzzles.

## Requirements

- C++ Compiler (GCC, Clang, MSVC, etc.)
- Raylib library
- nlohmann/json library

## Installation


```sh
git clone https://github.com/yourusername/sudoku-solver.git
cd sudoku-solver


## Building
    
```bash
cmake -S . -B build
cmake --build build
```

## Running

```bash
.\build\Debug\raylib_main.exe
```
## Build Release

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```
