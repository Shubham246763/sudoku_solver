#include "sudoku.h"

vector<vector<int>> generateSudoku() {
  vector<vector<int>> grid(9, vector<int>(9, 0));
  // Fill diagonal boxes to ensure the puzzle has a valid solution
  for (int i = 0; i < 9; i += 3) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        int num;
        do {
          num = rand() % 9 + 1;
        } while (!isSafe(grid, i + j, i + k, num));
        grid[i + j][i + k] = num;
      }
    }
  }
  return grid;
}
