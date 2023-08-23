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
    return -1; 
}
node *build_tree(int postorder[], int inorder[], int start, int end)
{
    static int idx = end; // here start from idx=end as root is on last index in postorder
    if (start > end)
    {
        return NULL;
    }

    int curr = postorder[idx];
    idx--;
    node *root = new node(curr);
    if (start == end)
    {
        return root;
    }
    int pos = search(inorder, start, end, curr);
    root->right = build_tree(postorder, inorder, pos + 1, end); // here first call for right then left
    root->left = build_tree(postorder, inorder, start, pos - 1); 
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
    int postorder[] = {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3};
    node *root = build_tree(postorder, inorder, 0, 4);
    print_inorder(root);
    return 0;
}