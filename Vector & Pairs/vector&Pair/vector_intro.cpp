#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
// they are like dynamic arrays
int main()
{
    vector<int> v;
    // to add element at eh end
    v.push_back(1);
    v.push_back(5);
    v.push_back(2);
    // to print
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    // or
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " "; // use * as it is a pointer
    }
    cout << endl;
    // or
    for (auto element : v)
    {
        cout << element << " ";
    }
    cout << endl;
    // ****to pop the end element
    v.pop_back(); // now the 1 5

    // *****other way of initialization
    vector<int> v2(3, 50); // means 3 elements each equal to 50

    //******To swap the two vectors
    swap(v, v2);
    for (auto element : v)   //it will contain the values of v2 now
    {  
        cout << element << " ";
    }
    cout << endl;
    for (auto element : v2)
    {
        cout << element << " ";
    }
    cout << endl;
    //*****To sort the vector 
    vector<int> v3{3,5,6,8,10,7,8,6};   //initialization like an array
     
    sort(v3.begin(),v3.end());  //it is present in <algorithm> file
    for(auto element:v3){
        cout<<element<<" ";
    }
    return 0;
}