#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
// The game of snake and ladder.Yor are at square 1 and have to reach 100.
// For given ladders and snake , find the minimum steps to reach
// BFS approach
int main()
{
    int ladders, snake;
    cin >> ladders;
    map<int, int> lad;
    map<int, int> snak;
    for (int i = 0; i < ladders; i++)
    {
        int u, v; // 2 ->({3,90},_56,76)
        cin >> u >> v;
        lad[u] = v;
    }
    cin >> snake;
    for (int i = 0; i < snake; i++) // 3 ->({99,10},{30,20},{20,5})
    {
        int u, v;
        cin >> u >> v;
        snak[u] = v;
    }
    int moves = 0;
    queue<int> q;
    vector<bool> vis(101, false);
    bool found = false;
    q.push(1);
    vis[1] = true;
    while (!q.empty() && found == false)
    {
        int size = q.size();
        while (size--)
        {
            int t = q.front();
            q.pop();
            for (int i = 1; i <= 6; i++)
            {
                if (t + i == 100)
                {
                    found = true;
                }
                else if (t + i < 100 && lad[t + i] && !vis[lad[t + i]])
                {
                    vis[lad[t + i]] = true;
                    if (lad[t + i] == 100)
                    {
                        found = true;
                    }
                    q.push(lad[t + i]);
                }
                else if (t + i < 100 && snak[t + i] && !vis[snak[t + i]])
                {
                    vis[snak[t + i]] = true;
                    if (snak[t + i] == 100)
                    {
                        found = true;
                    }
                    q.push(lad[t + i]);
                }
                else if (t + i < 100 && !vis[t + i] && !snak[t + i] && !lad[t + i])
                {
                    vis[t + i] = true;
                    q.push(t + i);
                }
            }
        }
        moves++;
    }
    // To Print the answer
    if (found)
    {
        cout << moves << endl;
    }

    return 0;
}