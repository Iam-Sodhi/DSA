#include <iostream>
using namespace std;
// N_Queen problem --> place n queens in n*n board such that they don't kill each other
bool isSafe(int **a, int x, int y, int n)
{
    // We need to check for two upper diagonals and column (upward). not for the current row

    for (int i = 0; i < x; i++) // checking the column
    {
        if (a[i][y] == 1)
        {
            return false;
        }
    }
    int s, t;
    // checking the left upward diagonal
    s = x;
    t = y;
    while (s >= 0 && t >= 0)
    {
        if (a[s][t] == 1)
        {
            return false;
        }
        s--;
        t--;
    }
    // Checking the right upward diagonal
    s = x;
    t = y;
    while (s >= 0 && t < n)
    {
        if (a[s][t] == 1)
        {
            return false;
        }
        s--;
        t++;
    }

    return true;
}
bool N_queen(int **a, int x, int n) // we don't need y(column) here as unlike rat in maze problem we don't need to check for next column in it
{
    if (x >= n) // here n not n-1;
    {
        return true;
    }
    for (int col = 0; col < n; col++)
    {
        if (isSafe(a, x, col, n))
        {
            a[x][col] = 1;

            {
                if (N_queen(a, x + 1, n)) // now check for next row no need to check for next column
                {
                    return true;
                }
                a[x][col] = 0; // backtracking
                                // return false; // don't do it here  it will exit the loop and not check for other loops
            }
        }
    }

    return false;
}
int main()
{
    int n;
    cin >> n;  //n
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }
    if (N_queen(arr, 0, n))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}