#include <iostream>
using namespace std;
// Find the first ans last occurrence of the given element in the array
int first_occ(int a[], int n, int i, int key) // n-> size, i is the index , key is the element which we have to find
{
    if (i == n)
    {
        return -1;
    }

    if (a[i] == key)
    {
        return i;
    }
    return first_occ(a, n, i + 1, key); // to increase the index
}
// int last_occ(int a[], int i, int key) // start from last index
// {

//     if (a[i] == key)
//     {
//         return i;
//     }
//     return last_occ(a, i - 1, key);
// }
// OR
int last_occ(int a[], int n, int i, int key)
{
    if (i == n)
    {
        return -1;
    }

    int rest_arr = last_occ(a, n, i + 1, key);
    if (rest_arr != -1)
    {
        return rest_arr;
    }

    if (a[i] == key)
    {
        return i;
    }
    return -1;
}

int main()
{
    int a[] = {1, 4, 2, 4, 3, 2, 2, 1};
    cout << first_occ(a, 8, 0, 2) << endl;
    cout << last_occ(a, 8, 0, 2);
    return 0;
}