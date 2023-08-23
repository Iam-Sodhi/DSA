#include <iostream>
#include <queue>
using namespace std;
// Two types of Searching-> Recursive and iterative
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
int searching(node *root, int key)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == key)
    {
        return 1;
    }
    else if (key < root->data)
    {
        return searching(root->left, key);
    }
    else
    {
        return searching(root->right, key);
    }
}
// Iterative approach
int search_iter(node *root, int key)
{

    while (root != NULL)
    {
        if (root->data == key)
        {
            return 1;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return 0;
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
    cout << searching(root, 6) << endl;
    cout << searching(root, 9) << endl;
    cout<<search_iter(root,1)<<endl;
    cout<<search_iter(root,10)<<endl;
    return 0;
}