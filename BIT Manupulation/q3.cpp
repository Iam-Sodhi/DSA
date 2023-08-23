#include <iostream>
using namespace std;
// Generate all possible subsets of a set
void subsets(char a[], int n)
{
    for (int i = 0; i < (1 << n); i++) // (1<<n) is equal to 2^n  (total no of subsets n elements can have )
    {
        for (int j = 0; j < n; j++)
        {
            if ((i & (1 << j)) != 0)
            {
                cout << a[j] << " ";
            }
        }
        cout << endl;
    }
}
int main()
{
    char a[4] = {'A', 'B', 'C', 'D'};
    subsets(a, 4);
    return 0;
}