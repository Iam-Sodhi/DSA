#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Given a 2D board containing X and O , capture all regions surrounded by X.
// A region is captured by flipping all O's into X's in that surrounded region.
void change(vector<vector<char>> &board, int i, int j)
{
    board[i][j] = '*';
    // Below is the trick to traverse all the neighbours in 2D
    int x[] = {0,0,-1,1};
    int y[] = {1,-1,0,0};
    for (int k = 0; k < 4; k++)
    {
        int cx = i + x[k];
        int cy = j + y[k];
        // Now checking agoin
        if (cx >= 0 && cx < board.size() && cy >= 0 && cy < board[0].size() && board[cx][cy] == 'O') //*** board[0].size() will give m(no of columns) and board.size() give n
        {
            change(board, cx, cy);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m)); // size n*m
    // Here n and m are 4 ,4
    //  X X X X
    //  X O O X
    //  X X O X
    //  X O X X
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    // Making O's on the sides as '*'
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1 )
            {   if (board[i][j]=='O')
            {
                 change(board, i, j);
            }
            
              
            }
        }
    }
    // Now converting those O into X which can't be captured(are not *)
  for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'O')
            {
                board[i][j] = 'X';
            }
        }
    }
    // Now rechanging '*' into O
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == '*')
            {
                board[i][j] ='O';
            }
        }
    }

    // Printing the answer
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << board[i][j] << " ";
        }
        cout<<endl;
    }

    return 0;
}