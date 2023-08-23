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
int count_nodes(node* root){
    if (root==NULL)
    {
        return 0;
    }
    
    return count_nodes(root->left) + count_nodes(root->right) +1;
}
int Sumof_nodes(node* root){
    if (root==NULL)
    {
        return 0;
    }
    
    return Sumof_nodes(root->left) + Sumof_nodes(root->right) +root->data;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(7);
    /*  1
      / \
     2   3
    / \   \
   4   5   7
   */
  cout<<count_nodes(root)<<endl;
  cout<<Sumof_nodes(root)<<endl;
    return 0;
}