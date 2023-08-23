#include <iostream>
#include <queue>
using namespace std;
//build Balanced BST from sorted array
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
node *balancedBSTfromSortedarray(int a[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    node* root= new node(a[mid]);
    root->left = balancedBSTfromSortedarray(a, start, mid - 1);
    root->right = balancedBSTfromSortedarray(a, mid + 1, end);
    return root;
}

void preorder(node* root){
    if (root==NULL)
    {
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    
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
 int arr[]={10,20,30,40,50};
 int n=5;
  node* root= balancedBSTfromSortedarray(arr,0,n-1);
   preorder(root);
   cout<<endl;
   inorder(root);
   
    return 0;
}