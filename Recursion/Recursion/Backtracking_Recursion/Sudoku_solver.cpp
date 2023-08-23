#include <iostream>
#include <vector>
using namespace std;
// YOu have been given a Sudoku Puzzle. The empty cells of the sudoku are filled with zeroes and the rest of the cells are filled with integers from 1-9
// Your task is to fill all the empty cells such that the final matrix represents a Sudoku solution.
// Sodoku must satisfy the following conditions:
// Each row as well as each column has all elements from 1 to 9 wchih occur exactly once
// Each of the digiits 1-9 must occur exactly once in each of the 9, (3*3) sub-grids of the grid
bool isSafe(int row, int col, vector<vector<int>> &grid, int val)
{
    for (int i = 0; i < grid.size(); i++)
    {
        //  first check if row contains any element same as val
        if (grid[row][i] == val)
        {
            return false;
        }
        // Now check for that col
        if (grid[i][col] == val)
        {
            return false;
        }
        // To check the 3*3 sub grids -> Learn the formula
        if (grid[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
        {
            return false;
        }
    }
    return true;
}
bool SudokuSolver(vector<vector<int>> &grid)
{
    // firstly traverse over the whole grid
    // grid.size() = grid.size[0]=9  here
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 0) // if grid is empty at that place
            {
                // Now see which value from 1-9 will be safe to put in empty space
                for (int k = 1; k <= 9; k++)
                {
                    if (isSafe(i, j, grid, k))
                    {
                        grid[i][j] = k;
                        //recursive call
                        bool aglaSolutionPossible = SudokuSolver(grid);
                        if (aglaSolutionPossible)
                        { 
                            return true;
                        }
                        else
                        {
                            grid[i][j] = 0; // Backtracking
                        }
                    }
                }
                return false; // agar 1-9 values ko empty space pe check krne ke baad bhi true nhi return kr reha then false
            }
        }
    }
    return true;
}
int main()
{
    vector<vector<int>> grid =
        {{3, 0, 6, 5, 0, 8, 4, 0, 0},
         {5, 2, 0, 0, 0, 0, 0, 0, 0},
         {0, 8, 7, 0, 0, 0, 0, 3, 1},
         {0, 0, 3, 0, 1, 0, 0, 8, 0},
         {9, 0, 0, 8, 6, 3, 0, 0, 5},
         {0, 5, 0, 0, 9, 0, 6, 0, 0},
         {1, 3, 0, 0, 0, 0, 2, 5, 0},
         {0, 0, 0, 0, 0, 0, 0, 7, 4},
         {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    SudokuSolver(grid);
    for (auto it : grid)
    {
        for (auto c : it)
        {
            cout << c << " ";
        }
        cout << endl;
    }
//    cout<<endl;
//    for (int i = 0; i < grid.size(); i++)
//    {
//        for (int j = 0; j < grid[0].size(); j++)
//        {
//             cout<<grid[i][j]<<" ";
//        }
//        cout<<endl;
       
//    }
   
    return 0;
}