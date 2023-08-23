#include <iostream>
#include <queue>
using namespace std;
// Two methods
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
bool check_BST(node *root, int min, int max)
{
    if (root == NULL)

    {
        return true;
    }
    if (min != INT8_MIN && root->data <= min)
    {
        return false;
    }
    if (max != INT8_MAX && root->data >= max)
    {
        return false;
    }
    int leftvalid = check_BST(root->left, min, root->data);
    int rightvalid = check_BST(root->right, root->data, max);
    return leftvalid && rightvalid;
}
// Method 2
int isBST(node *root)
{
    static node *prev = NULL;
    if (root != NULL)
    { // we just need to apply same principle as inorder traversal
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data) // inorder traversal of BST will give an ascending order
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    return 1; // if null then it can be said BST
}
void inorder_print(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder_print(root->left);
    cout << root->data << " ";
    inorder_print(root->right);
}
int main()
{
    node *root = new node(5);
    root->left = new node(2);
    root->right = new node(8);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->right = new node(9);
    /* 5
      / \
     2   8
    / \   \
   1   3   9
   */
    cout << check_BST(root,INT8_MIN,INT8_MAX) << endl;
    inorder_print(root); // inorder traversal of BST will give an ascending order
    return 0;
}