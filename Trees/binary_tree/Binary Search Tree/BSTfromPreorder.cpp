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
node *makeBST_preorder(int preorder[], int *pre_idx, int n, int key, int min, int max)
{  //****here use *pre_idx not pre_idx otherwise wrong output
    if (*pre_idx >= n)
    {
        return NULL;
    }
    node *root = NULL;
    if (key < max && key > min)
    {
        root = new node(key);
        *pre_idx = *pre_idx + 1;
        if (*pre_idx < n)
        {
            root->left = makeBST_preorder(preorder, pre_idx, n, preorder[*pre_idx], min, key);
        }
        if (*pre_idx < n)
        {
            root->right = makeBST_preorder(preorder, pre_idx, n, preorder[*pre_idx], key, max);
        }
    }
    return root;
}
void print_preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    print_preorder(root->left);
    print_preorder(root->right);
}
int main()
{
    /* 5
      / \
     2   8
    / \   \
   1   3   9
   */
    int preorder[] = {5,2,1,3,8,9};
    int n = 6;
    int pre_idx = 0;
    node *root = makeBST_preorder(preorder, &pre_idx, n, preorder[0], INT8_MIN, INT8_MAX);
  print_preorder(root);
    return 0;
}