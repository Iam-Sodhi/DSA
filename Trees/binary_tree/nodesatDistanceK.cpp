#include <iostream>
#include <queue>
using namespace std;
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
void printSubtreeNodes(node *root, int k)
{
    if (root == NULL || k < 0)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << " ";
    }
    printSubtreeNodes(root->left, k - 1);
    printSubtreeNodes(root->right, k - 1);
}
int NodesatdistK(node *root, node *target, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root == target)
    {
        printSubtreeNodes(root, k);
        return 0;
    }

    int dl = NodesatdistK(root->left, target, k); // here don't decrease k
    
    if (dl != -1)                                 // means target has been found in left subtree
    {
        if (dl + 1 == k) // distance of root->left from target is dl but of root from target is dl+1
        {
            cout << root->data << " ";
        }
        else
        {                                               // here use root->right not root->left
            printSubtreeNodes(root->right, k - dl - 2); // here we have to minus 2 as dist from root->right not root and dl is also form target to root->left
        }
        return 1 + dl;
    }
    int dr = NodesatdistK(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printSubtreeNodes(root->left, k - dr - 2);
        }
        return 1 + dr;
    }
    return -1;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(7);
    /*  1
      / \
     2   3
    / \   \
   4   5   7
   */
    NodesatdistK(root, root->left, 1);
    return 0;
}