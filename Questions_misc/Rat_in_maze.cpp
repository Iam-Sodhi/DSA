#include <iostream>
using namespace std;
// Given a 2D matrix where 0 shows the pts of barriers & 1 show right pts. Then Show the path in form of matrix to go to final point.
bool isSafe(int **a, int X, int Y, int n)
{
    if (X < n && Y < n && a[X][Y] == 1)
    {
        return true;
    }
    return false;
}
bool ratinMaze(int **a, int X, int Y, int n, int **sol)
{
    if (X == (n - 1) && Y ==( n - 1))
    {   sol[X][Y]=1;
        return true;
    }

    if (isSafe(a, X, Y, n))
    {
        sol[X][Y] = 1;
        if (ratinMaze(a, X + 1, Y, n, sol))
        {
            return true;
        }
        if (ratinMaze(a, X, Y + 1, n, sol))
        {
            return true;
        }
        sol[X][Y] = 0; // backtracking
      //  return false;  // it won't make any difference
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    // Dynamically iniitalize 2D array
    int **a = new int*[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n];
    }
    // 1 0 1 0 1
    // 1 1 1 1 1
    // 0 1 0 1 0
    // 1 0 0 1 1
    // 1 1 1 0 1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    int **solArray = new int*[n];
    for (int i = 0; i < n; i++)
    {
        solArray[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            solArray[i][j] = 0;
        }
    }
    cout<<endl;
    if (ratinMaze(a, 0, 0, n, solArray))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << solArray[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}