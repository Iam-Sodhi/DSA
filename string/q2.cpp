#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
//find maximum number from the given numeric string
int main()
{	
   string s="23154";
//    sort(s.begin(),s.end()); // we get sorted string in ascending order
   
//    reverse(s.begin(),s.end());
sort(s.begin(),s.end(),greater<char>()); // to sort in descending order
   cout<<s;
    return 0;
}