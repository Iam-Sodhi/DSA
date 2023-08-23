#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
// For a given array(Having one digit number), check if any subarray os size k exists such that concatenation of elements form a palindrome
bool ifPalindrome(int num)
{
    int temp = num;
    int n = 0;
    while (temp > 0)
    {
        n = n * 10 + temp % 10;
        temp /= 10;
    }
    if (n == num)
    {
        return true;
    }
    return false;
}

int subarrayPalindrome(vector<int> a, int n, int k)
{
    int sum = 0;
    int i;
    for (i = 0; i < k; i++)
    {
        sum = sum * 10 + a[i];
    }
    if (ifPalindrome(sum))
    {
        return 0;
    }
    while (i < n)
    {
        sum = (sum % (int)pow(10, k - 1)) * 10 + a[i];
        if (ifPalindrome(sum))
        {
            return i - k + 1; // on first time it will return 1 index as i=k here
        }
        i++;
    }

    return -1;
}

int main()
{
    vector<int> arr = {2, 3, 5, 1, 1, 5};
    int k = 4;
    int ans = subarrayPalindrome(arr, arr.size(), k);
    if (ans == -1)
    {
        cout << "There is no Palindrome" << endl;
    }
    else
    {
        for (int i = ans; i < ans + k; i++)
        {
            cout << arr[i] << " ";
        }
    }

    return 0;
}