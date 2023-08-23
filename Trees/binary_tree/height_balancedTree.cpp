#include <iostream>
#include <queue>
using namespace std;
// Height Balanced Tree:For each node, the difference bw the heights of the left subtree& right subtree <=1
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int n)
    {
        data = n;
        left = NULL;
        right = NULL;
    }
};
// here we are n't going to use other height function(height&diameter) as then O(n^2)
//  we will use pointer approach which will have O(n)
bool BalancedHeighttree(node *root, int *height)
{
    if (root == NULL)
    {
        return true;
    }
    int lh = 0, rh = 0;
    if (BalancedHeighttree(root->left, &lh) == false)
    {
        return false;
    }
    if (BalancedHeighttree(root->right, &rh) == false)
    {
        return false;
    }
    *height = max(lh, rh) + 1;
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(7);
    root->right->left = new node(6);
    /*  1
      /  \
     2    3
    / \  / \
   4   5 6 7
   */
    int height = 0;
    if (BalancedHeighttree(root, &height))
    {
        cout << "Balanced Tree" << endl;
    }
    else
    {
        cout << "Unbalanced Tree" << endl;
    }

    node *root1 = new node(1);
    root1->left = new node(2);
    root1->left->left = new node(3);
    int height1=0;
        if (BalancedHeighttree(root1, &height1))
    {
        cout << "Balanced Tree" << endl;
    }
    else
    {
        cout << "Unbalanced Tree" << endl;
    }

    return 0;
}