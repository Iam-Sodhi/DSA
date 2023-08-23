#include <iostream>
using namespace std;
// find a unique number from the array where all the elements are present thrice, except one element
bool getbit(int n, int pos)
{
    return ((n & 1 << pos) != 0);
}
int setbit(int n, int pos)
{
    return (n | (1 << pos));
}
int unique(int a[], int n)
{
    int result = 0;
    for (int i = 0; i < 32; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (getbit(a[j], i))
            {
                sum++;
            }
        }
        if (sum % 3 != 0)
        {
            result = setbit(result, i);
        }
    }
    return result;
}
int main()
{
    int a[] = {1, 2, 3, 4, 2, 1, 3, 1, 2, 3};
    int n = sizeof(a) / sizeof(a[0]);
    cout << unique(a, n);
    return 0;
}