#include <iostream>
#include <vector>
#include <queue>
// Given K sorted arrays. Merge them into a single sorted array.
using namespace std;
// We are gonna use Heap method here
class node
{
public:
    int data;
    int i;
    int j;
    node(int data, int a, int b)
    {
        this->data = data;
        this->i = a;
        this->j = b;
    }
};
class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};
vector<int> MergedArray(vector<vector<int>> a, int k)
{                                                       // First put the first elements of all the arrays in min heap
    priority_queue<node *, vector<node *>, compare> pq; //******Here we use compare class as the elements are node*
    for (int i = 0; i < k; i++)
    {
        node *t = new node(a[i][0], i, 0);
        pq.push(t);
    }
    vector<int> ans;
    // Now until it is not empty, pop the top element and then add the next element of that array if it exists.
    while (pq.size() > 0)
    {
        node *temp = pq.top();
        pq.pop();
        // Push this element in the ans vector
        ans.push_back(temp->data);
        // Now check if the next element of that array exist , if yes push it in the min heap
        int row = temp->i;
        int col = temp->j;
        if ((col + 1) < a[row].size())
        {
            node *next = new node(a[row][col + 1], row, col + 1);
            pq.push(next);
        }
    }
    return ans;

}
int main()
{   vector<vector<int> > a={{1},{2},{3},{3,5,9},{4},{1,2,3,8}};
    int k= a.size();
     vector<int> ans= MergedArray(a,k);
     for (int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
     }
    return 0;
}