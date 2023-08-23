#include <iostream>
using namespace std;
// Number of paths possible in a maze
int Paths_maze(int n, int i, int j)
{
    if (i == n - 1 && j == n - 1)
    {
        return 1;
    }
    if (i > n - 1 || j > n - 1)
    {
        return 0;
    }

    return Paths_maze(n, i + 1, j) + Paths_maze(n, i, j + 1);
}
int main()
{
    int n = 3;
    cout << Paths_maze(n, 0, 0);
    return 0;
}