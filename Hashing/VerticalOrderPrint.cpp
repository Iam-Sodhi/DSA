#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
using namespace std;
// Print the binary tree in vertical order
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
void verticalOrderPrint(node *root, map<int,vector<int>> &mp, int dist) //here pass map by reference
{

    if (root == NULL)
    {
        return;
    }
    mp[dist].push_back(root->data);
    verticalOrderPrint(root->left, mp, dist - 1);
    verticalOrderPrint(root->right, mp, dist + 1);
}
int main()
{
    node *root = new node(10);
    root->left = new node(7);
    root->right = new node(4);
    root->left->left = new node(3);
    root->left->right = new node(11);
    root->right->left = new node(14);
    root->right->right = new node(8);
//       10
//      /   \
//     7     4
//    / \   / \
//   3   11/   8
//       14

    int distance = 0; // distance referes to the horizontal distance of nodes from vertical line passing throudh the root node
    map<int,vector<int>> mp;
    verticalOrderPrint(root, mp, distance);
    
//The default behavior of map is to store elements in ascending order. , hence will start print the elements falling on leftmost vertical line
    for(auto i: mp){
        
        for (int j = 0; j < i.second.size(); j++)
        {
            cout<<i.second[j]<<" ";
        }
        cout<<endl;
        
    }

    return 0;
}