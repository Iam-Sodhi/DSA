#include <bits/stdc++.h>
using namespace std;
// Write a program to solve a Sudoku puzzle by filling the empty cells.
// A sudoku solution must satisfy all of the following rules:
// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.

//*****Not related to this question but subGrid[3*(i/3)+j/3] is the number of Subgrid if i-> row and j->columns of 9*9 grid. It is used to find if the sudoku is valid or not.******
bool isPossible(vector<vector<char>> &board, int row, int col, char num)
{

    for (int i = 0; i < 9; i++)
    {
        // to check for row
        if (board[row][i] == num)
            return false;
        // to check for column
        else if (board[i][col] == num)
            return false;

        // to check for that sub board
        else if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num)
            return false;
    }

    return true;
}

bool solve(vector<vector<char>> &board)
{

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
            {

                for (int k = 1; k <= 9; k++)
                {
                    if (isPossible(board, i, j, k + '0'))
                    {
                        board[i][j] = k + '0';
                        bool aagePossible = solve(board);
                        if (aagePossible)
                            return true;
                        else
                        {
                            board[i][j] = '.'; // backtracking
                        }
                    }
                }

                return false; // agar 1-9 values ko empty space pe check krne ke baad bhi true nhi return kr reha then false
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<char>> &board)
{

    solve(board);
}
int main()
{
    return 0;
}