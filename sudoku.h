#ifndef SUDOKU_H
#define SUDOKU_H

#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

bool isSafe(const vector<vector<int>> &grid, int row, int col, int num);
bool solveSudoku(vector<vector<int>> &grid);
void printGrid(const vector<vector<int>> &grid);
vector<vector<int>> generateSudoku();

#endif // SUDOKU_H
