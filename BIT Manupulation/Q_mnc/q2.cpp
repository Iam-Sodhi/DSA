#include <iostream>
using namespace std;
// Find the two unique numbers in the array where all elements, except two elements , are present twice
bool getbit(int n, int pos)
{
    return ((n & 1 << pos) != 0);
}
void unique(int a[], int n)
{
    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum = xorsum ^ a[i];
    }
    int tempxor = xorsum;
    int setbit=0;
    int pos = 0;
    while (setbit!=1)
    {
        setbit = xorsum & 1;
        pos++;
        xorsum= xorsum>>1;
    }

    int xorsum1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (getbit(a[i], pos = 1))
        {
            xorsum1 = xorsum1 ^ a[i];
        }
    }
    cout << xorsum1 << " " << (xorsum1 ^ tempxor);
}
int main()
{
    int a[] = {1, 2, 3, 4, 1, 6, 5, 2, 4, 3};
    int n = sizeof(a) / sizeof(a[0]);
    unique(a, n);
    return 0;
}