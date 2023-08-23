#include <bits/stdc++.h>
using namespace std;
// We all have might have played the game called Maze in our childhood.A maze is a path or collection of paths, typically from an entrance to a goal.
// Here,a rat placed at $(0, 0)$ in a square matrix $m[][]$ of order n and has to reach the destination at $(n-1, n-1)$.
// Your task is to display a sorted array of strings denoting all the possible directions which the rat can take to reach the destination at (n-1, n-1).
// The directions in which the rat can move are $'U'$(up), $'D'$(down), $'L'$ (left), $'R'$ (right).

bool isValid(vector<vector<int>> &arr, int n, int i, int j, vector<vector<bool>> &vis)
{
    if (i < 0 || j < 0 || i >= n || j >= n || (vis[i][j] == true) || (arr[i][j] == 0))
        return false;
    return true;
}
void solve(vector<vector<int>> &arr, int n, int i, int j, vector<vector<bool>> &vis, vector<string> &ans, string path)
{
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(path);
        return;
    }
    // now we have to store the strings in sorted order hence
    // we will firstly check  for D(down)->L(left) -> R(right)-> U(up)
    int dr[] = {1, 0, 0, -1};
    int dc[] = {0, -1, 1, 0};
    char dir[] = {'D', 'L', 'R', 'U'};

    for (int k = 0; k < 4; k++)
    {
        int nr = i + dr[k];
        int nc = j + dc[k];
        if (isValid(arr, n, nr, nc, vis))
        {
            vis[i][j] = true;
            solve(arr, n, nr, nc, vis, ans, path + dir[k]);
            vis[i][j] = false;
        }
    }
}

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> arr(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }

        vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));
        vector<string> ans;
        string path = "";
        if (arr[0][0] == 0)
            cout << "";

        else
        {
            solve(arr, n, 0, 0, visited, ans, path);

            for (int i = 0; i < ans.size(); i++)
            {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}