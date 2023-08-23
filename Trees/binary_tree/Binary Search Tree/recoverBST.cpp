#include <iostream>
#include <algorithm>
using namespace std;
// If two numbers in valid BST are swapped then recover the BSt
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
 void swap( int* a, int* b){
    int temp= *a;
    *a=*b;
    *b= temp;
 }
void utility(node *root, node **first, node **mid, node **last, node **prev)
{
    if (root == NULL)
    {
        return;
    }
    utility(root->left, first, mid, last, prev);  //Use concept of inorder traversal
    if (*prev != NULL && root->data < (*prev)->data)
    {
        if (!(*first))
        {
            *first = *prev;
            *mid = root;
        }
        else
        {
            *last = root;
        }
    }
    *prev=root;
    utility(root->right,first,mid,last,prev);
}

void recoverBST(node *root)
{
    node *first;
    node *mid;
    node *last;
    node *prev;
    first = NULL;
    mid = NULL;
    last = NULL;
    prev = NULL;
    utility(root, &first, &mid, &last, &prev);
    if (first && last)
    {
        swap(&(first->data),&(last->data));
    }
    else if (first && mid)
    {
        swap(&(first->data),&(mid->data));
    }
    
    
}
void inorder(node* root){
if (root==NULL)
{
    return;
}
inorder(root->left);
cout<<root->data<<" ";
inorder(root->right);

}
int main()
{
    node *root = new node(5);  //here 2 & 8 are in wrong places
    root->left = new node(8);
    root->right = new node(2);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->right = new node(9);
    /* 5
      / \
     8   2
    / \   \
   1   3   9
   */
  inorder(root);
  recoverBST(root);
  cout<<endl;
  inorder(root);
    return 0;
}