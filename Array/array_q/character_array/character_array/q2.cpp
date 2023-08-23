#include <iostream>
#include <cstring>
using namespace std;
// largest word in the sentence
int main()
{
    int n; // no of letters/size
    cin >> n;
    cin.ignore();
    char arr[n + 1];
    cin.getline(arr, n); // for considering whitespaces
    cin.ignore();
    int curr_len = 0;
    int max_len = 0;
    int st = 0, max_st = 0;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] == ' ')
        {
            if (curr_len > max_len)
            {
                max_len = curr_len;
                max_st = st;
            }
            curr_len = 0;
            st = i + 1;
        }
        else
        {
            curr_len++; // increase it only when it is not white space so use else
        }
    }
    // to tackle last word
    if (curr_len > max_len)
    {
        max_len = curr_len;
        max_st = st;
    }

    cout << "The maximum length of the word " << max_len << endl;
    //To print that word
    for (int i = 0; i < max_len; i++)
    {
        cout<<arr[i+max_st];
    }
    
    return 0;
}
