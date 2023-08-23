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
node* insertion(node* root, int key){
    if (root==NULL)
    {
        return new node(key);
    }
    else if (key<root->data)
    {
        root->left=insertion(root->left,key);
    }
    else
    {
        root->right= insertion(root->right,key);
    }
    return root;
    
}
void print_inorder(node* root){
    if (root==NULL)
    {
        return ;
    }
    print_inorder(root->left);
    cout<<root->data<<" ";
    print_inorder(root->right);
    
}
int main()
{
    /* 5
      / \
     2   8
    / \   \
   1   3   9
   */
  node* root= NULL;
  root=insertion(root,5);
  insertion(root,3);
  insertion(root,9);
  insertion(root,8);
  insertion(root,1);
  insertion(root,2);
   
   //To check print inorder
   print_inorder(root);
    return 0;
}