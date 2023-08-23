#include <iostream>
#include <queue>
using namespace std;
// Shortest Distance b/w two nodes
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
node *lca(node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    node *Left = lca(root->left, n1, n2);
    node *right = lca(root->right, n1, n2);
    if (left != NULL && right != NULL)
    {
        return root;
    }
    if (left == NULL && right == NULL)
    {
        return NULL;
    }

    if (left != NULL)
    {
        return lca(root->left, n1, n2);
    }
    if (right != NULL)
    {
        return lca(root->right, n1, n2);
    }
}
int Find_distance(node *root, int k, int dis)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == k)
    {
        return dis;
    }
    int left = Find_distance(root->left, k, dis+1);
    if (left != -1)
    {
        return left;
    }
    return Find_distance(root->right, k, dis + 1);
}
int shortest_distance(node *root, int n1, int n2)
{
    node *LCA = lca(root, n1, n2);
    int d1 = Find_distance(LCA, n1, 0);
    int d2 = Find_distance(LCA, n2, 0);

    return d1 + d2;
}
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->right = new node(5);
    /* 1
      / \
     2   3
    /     \
   4       5
   */
    cout<<shortest_distance(root,4,5);
    return 0;
}