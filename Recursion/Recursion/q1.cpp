#include <iostream>
using namespace std;
// to check if the array is sorted(stricly increasing)

// int check(int a[], int h)
// {

//     if (h == 1)
//     {
//         if (a[h - 1] < a[h])
//         {
//             return 1;
//         }
//         else
//         {
//             return 0;
//         }
//     }
//     else
//     {
//         if (a[h - 1] > a[h])
//         {
//             return 0;
//         }
//     }

//     return check(a, h - 1);
// }

bool check(int a[], int idx)

{   
    if (idx == 0)
    {
        return true;
    }
  if (a[idx]>a[idx-1])
  {
    return check(a,idx-1);
  }
  else
  {
    return false;
  }
  
   
}

int main()
{
    int a[6] = {5, 6, 7, 8, 9, 10};
    int n=6;
    cout << check(a, n-1);
    return 0;
}