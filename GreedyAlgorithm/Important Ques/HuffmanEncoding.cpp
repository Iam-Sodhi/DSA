#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
// Given a string of diff characters of size n and their corr freq,f[] i.e. a character S[i] has freq f[i].
// Your task is to build a Huffman tree print all the huffman codes in preorder traversal of tree.
// NOTE: while merging if two nodes have the same value, then the node which occurs at first will be taken on the left of Binary tree and other to the right
// otherwise node with less value will be taken on the left of the subtree and the other one to the right
class node
{
public:
    node *left;
    node *right;
    int data;
    node(int val)
    {
        left = NULL;
        right = NULL;
        data = val;
    }
};

class cmp
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};
void traversal_pre(node* root, vector<string> &ans, string temp)
{   // temp is to store the build up string until we find the leaf node and then we will add to ans vector
    //base case when root is leaf nodes
    if (root->left==NULL && root->right==NULL)
    {
        ans.push_back(temp);
        return;
    }
    //preorder traversal
    traversal_pre(root->left, ans, temp+'0'); // 0 as given in Q
    traversal_pre(root->right, ans, temp+'1'); 
    
}
vector<string> HuffmanTree(vector<int> a, string s)
{
    // firstly make the Huffman tree using min heap where we start by pushing all elements in heap then adding two minimum freq elements , pushing the sum back into it
    priority_queue<node *, vector<node *>, cmp> mini;
    for (int i = 0; i < s.length(); i++)
    {
        node *temp = new node(a[i]);
        mini.push(temp);
    }
    while (mini.size() > 1)
    {
        node *l = mini.top(); //less value on left side 
        mini.pop();
        node *r = mini.top();
        mini.pop();
        node *parent = new node(l->data + r->data);
        parent->left=l;
        parent->right=r; 
        mini.push(parent);
    }
    //The last elements is left
    node* root= mini.top();
    // Now Tree has been made
    // It's time for traversal
    vector<string> ans;
    string temp="";
    traversal_pre(root,ans,temp);
    return ans;
}
int main()
{
    string s = "abcdef";
    vector<int> f = {5, 9, 12, 13, 16, 45};
   
     vector<string> ans=HuffmanTree(f,s);
     for(auto i: ans){
        cout<<i<<" ";
     }
    return 0;
}