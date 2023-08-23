#include <iostream>
using namespace std;
class node
{
public:
    node *left;
    node *right;
    int data;
    int height;
    node(int n)
    {
        data = n;
        height = 1;
        left=NULL;
        right=NULL;
    }
};
int getheight(node *Node)
{
    if (Node == NULL)
    {
        return 0;
    }
    return Node->height;
}
int BalanceFactor(node *Node)
{
    if (Node == NULL)
    {
        return 0;
    }
    return getheight(Node->left) - getheight(Node->right);
}
node *rightrotate(node *y)
{
    node *x = y->left;
    node *T = x->right;

    x->right = y;
    y->left = T;
    x->height = max(getheight(x->left), getheight(x->right)) + 1;
    y->height = max(getheight(y->left), getheight(y->right)) + 1;
    return x;
}
node *leftrotate(node *x)
{
    node *y = x->right;
    node *T = y->left;

    y->left = x;
    x->right = T;
    x->height = max(getheight(x->left), getheight(x->right)) + 1;
    y->height = max(getheight(y->left), getheight(y->right)) + 1;
    return y;
}
node *insertion(node *root, int key)
{
    if (root == NULL)
    {
        return new node(key);
    }
    if (key < root->data)
    {
        root->left = insertion(root->left, key);
    }
    else  if (key>root->data)
    {
        root->right = insertion(root->right, key);
    }
    root->height = max(getheight(root->left), getheight(root->right)) + 1;
    int BF = BalanceFactor(root);
    // left-left rotation
    if (BF > 1 && key < root->left->data)
    {
        return rightrotate(root);
    }
    // rihgt=right rotation
    if (BF < -1 && key > root->right->data)
    {
        return leftrotate(root);
    }
    if (BF > 1 && key > root->left->data)
    {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }
    if (BF < -1 && key < root->right->data)
    {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }

    return root;
}
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    node *root = NULL;
    root = insertion(root, 1);
    root = insertion(root, 2);
    root = insertion(root, 4);
    root = insertion(root, 5);
    root = insertion(root, 6);
    root = insertion(root, 3);

    preorder(root);
    return 0;
}