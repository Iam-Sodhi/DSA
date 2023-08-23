#include <iostream>
#include<cstring>
using namespace std;
//Check Palindrome
int main()
{	char a[]="nitin";
    int n=strlen(a);
    int verify=1;
    for (int i = 0; i <n; i++)
    {
        if (a[i]!=a[n-i-1])
        {
            verify=0;
            break;
        }
        
    }
    if (verify==1)
    {
        cout<<"The word is palindrome";
    }
    else
    {
        cout<<"The word is not a palindrome";
    }
    
    return 0;
}