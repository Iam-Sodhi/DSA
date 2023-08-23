#include <iostream>
#include <vector>
using namespace std;
// In the array of 0 & 1 , we may change upto k values from 0 to 1. Find the length of longest subarray that contains only 1s
int len_ones(vector<int> a, int k)
{
    int n = a.size();
    int ans = INT8_MIN;
    int zerocnt = 0;
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        if (a[j] == 0)
        {
            zerocnt++;
        }
        while (zerocnt > k)
        {
            if (a[i] == 0) // here a[i]
            {
                zerocnt--;
            }  
          

            i++;
        }
        int len = j - i + 1;
        ans = max(ans, len);
    }
    return ans;
}
int main()
{
    vector<int> a = {1, 1, 0, 0, 1};  
    int k=2;
    cout<<len_ones(a,k);

    return 0;
}