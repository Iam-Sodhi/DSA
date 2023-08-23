#include <iostream>
#include <vector>
using namespace std;
// Given a Binary Search Tree which is Complete binary tree.
//******Convert the BST into Min Heap such that the left child of the node are less than the right child
// Inorder of BST is the sorted array & in the min heap node < left & node < right  hence  ***** Node< left < right*****
//***** Node< left < right*****So We just need to change the structure of tree by travelling Preorder

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
node *insertion(node *root, int key)
{
    if (root == NULL)
    {
        return new node(key);
    }
    else if (key < root->data)
    {
        root->left = insertion(root->left, key);
    }
    else
    {
        root->right = insertion(root->right, key);
    }
    return root;
}
vector<int> inorder(node *root, vector<int> a)
{
    if (root != NULL)
    {
        inorder(root->left, a);
        a.push_back(root->data);
        inorder(root->right, a);
    }
    return a;
}
void FillPreorder(node *root, vector<int> inOrderArray, int idx)
{
    if (root != NULL)
    {
        root->data = inOrderArray[idx];
        FillPreorder(root->left, inOrderArray, idx++);
        FillPreorder(root->right, inOrderArray, idx++);
    }
}
int main()
{
    /* 5
     / \
    2   8
   / \   \
  1   3   */

    node *root = NULL;
    root = insertion(root, 5);
    insertion(root, 3);
    insertion(root, 8);
    insertion(root, 1);
    insertion(root, 2);
    vector<int> a;
    vector<int> inorderArray = inorder(root, a);
    FillPreorder(root, inorderArray, 0);
    //Now root->data= 1
    // root ka structure is min heap
    return 0;
}