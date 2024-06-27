#include "sudoku.h"

bool isSafe(const vector<vector<int>> &grid, int row, int col, int num) {
  for (int x = 0; x < 9; x++) {
    if (grid[row][x] == num || grid[x][col] == num)
      return false;
  }

  int startRow = row - row % 3, startCol = col - col % 3;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (grid[i + startRow][j + startCol] == num)
        return false;

  return true;
}

bool solveSudoku(vector<vector<int>> &grid) {
  int row, col;
  bool empty = true;
  for (row = 0; row < 9; row++) {
    for (col = 0; col < 9; col++) {
      if (grid[row][col] == 0) {
        empty = false;
        break;
      }
    }
    if (!empty)
      break;
  }

  if (empty)
    return true;

  for (int num = 1; num <= 9; num++) {
    if (isSafe(grid, row, col, num)) {
      grid[row][col] = num;
      if (solveSudoku(grid))
        return true;
      grid[row][col] = 0;
    }
  }
  return false;
}

void printGrid(const vector<vector<int>> &grid) {
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++)
      cout << grid[row][col] << " ";
    cout << endl;
  }
}

int main() {
  vector<vector<int>> grid = generateSudoku();
  cout << "Generated Sudoku Puzzle: " << endl;
  printGrid(grid);

  clock_t start = clock();
  if (solveSudoku(grid)) {
    clock_t end = clock();
    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Solved Sudoku: " << endl;
    printGrid(grid);
    cout << "$ Total Calculation Time: " << time_taken << " s" << endl;
  } else {
    cout << "No solution exists" << endl;
  }
  return 0;
}
