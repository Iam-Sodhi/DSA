#include <iostream>
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
int search(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }
    return -1; //though this case would not be there
}
node *build_tree(int preorder[], int inorder[], int start, int end)
{
    static int idx = 0; // here start from idx=0 as root is on this index in preorder
    if (start > end)
    {
        return NULL;
    }

    int curr = preorder[idx];
    idx++;
    node *root = new node(curr);
    if (start == end)
    {
        return root;
    }
    int pos = search(inorder, start, end, curr);
    root->left = build_tree(preorder, inorder, start, pos - 1); // here first call for left then right
    root->right = build_tree(preorder, inorder, pos + 1, end);
}
void print_inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    print_inorder(root->left);
    cout << root->data << " ";
    print_inorder(root->right);
}
int main()
{
    int preorder[] = {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3};
    node *root = build_tree(preorder, inorder, 0, 4);
    print_inorder(root);
    return 0;
}