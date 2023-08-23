#include <bits/stdc++.h>
using namespace std;
//*****Here we are using hashing for isSafe() function ******
// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
// Each solution contains a distinct board configuration of the n-queens' placement,
// where 'Q' and '.' both indicate a queen and an empty space, respectively.

void solve(int row, vector<string> &board, int n, vector<vector<string>> &ans, unordered_map<int, bool> &column, unordered_map<int, bool> &rightDiagonal, unordered_map<int, bool> &leftDiagonal)
{
    if (row == n)
    {
        ans.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++)
    {

        if (column[col] == false && rightDiagonal[row + col] == false && leftDiagonal[n - 1 + (col - row)] == false) //isSafe
        {
            board[row][col] = 'Q';
            rightDiagonal[row + col] = true;          // for north-east diagonal
            column[col] = true;                       // for that column
            leftDiagonal[n - 1 + (col - row)] = true; // for  north-west diagonal
            solve(row + 1, board, n, ans, column, rightDiagonal, leftDiagonal);
            // Backtracking
            board[row][col] = '.';
            rightDiagonal[row + col] = false;
            column[col] = false;
            leftDiagonal[n - 1 + (col - row)] = false;
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;

    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }
    unordered_map<int, bool> column;
    unordered_map<int, bool> rightDiagonal;
    unordered_map<int, bool> leftDiagonal;

    solve(0, board, n, ans, column, rightDiagonal, leftDiagonal);
}
int main()
{
    return 0;
}