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

node *precessor_inorder(node *root, int key)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
node *deletion(node *root, int key)
{ // searching the element

    if (root == NULL)
    {
        return NULL;
    }
    

    if (key < root->data)
    {
        root->left = deletion(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deletion(root->right, key);
    }
    // Deletion if key is found
    else
    { if (root->left==NULL)
    {
       node* temp= root->right;
       free(root);
       return temp;
    }
     else if (root->right==NULL)
     { node* temp=root->left;
       free(root);
       return temp;
     }
     
        node *ipre = precessor_inorder(root, key);
        root->data = ipre->data;
        root->left = deletion(root->left, ipre->data);
    }
    return root;
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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
    inorder(root);
    deletion(root, 8);
    cout << endl;
       inorder(root);
    deletion(root, 9);
    cout << endl;
       inorder(root);
    return 0;
}