#include <iostream>
#include <stack>
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
bool identicalBST(node* root1, node* root2){
    if (root1==NULL && root2==NULL)
    {
        return true;
    }
    else if (root1==NULL || root2==NULL)
    {
        return false;
    }
    else
    {
        bool cond1= root1->data==root2->data;
        bool cond2=identicalBST(root1->left, root2->left);
        bool cond3= identicalBST(root1->right, root2->right);

        if (cond1&& cond2&& cond3)
        {
            return true;
        }
        else
        {
            return false;
        }
        
        
    }
    
    
    
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
    node *root2 = new node(5);
    root2->left = new node(2);
    root2->right = new node(8);
    root2->left->left = new node(1);
    root2->left->right = new node(3);
    root2->right->right = new node(0);
    /* 5
     / \
    2   8
   / \   \
  1   3   0
  */
 if (identicalBST(root, root))
 {
    cout<<"Identical BST's";
 }
 else
 {
    cout<<"Not identical BST's";
 }
 cout<<endl;
 if (identicalBST(root, root2))
 {
    cout<<"Identical BST's";
 }
 else
 {
    cout<<"Not identical BST's";
 }
 
    return 0;
}