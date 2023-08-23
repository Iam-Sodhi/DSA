#include <iostream>
#include<climits>
using namespace std;
// Find information of the largest BST in hte given tree
class node
{  public:
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
struct info
{
    int size;
    int max;
    int min;
    int ans; // max size
    bool isBST;
};

info LargestBST(node *root)  //  bottom up approach is used
{
    if (root == NULL)
    {
        return {0, INT_MIN, INT_MAX, 0, true};
    }
    if (root->left == NULL && root->right == NULL) // for leaf node
    {
        return {1, root->data, root->data, 1, true};
    }
    info leftinfo = LargestBST(root->left);
    info rightinfo = LargestBST(root->right);
    info curr;
    curr.size =( 1+ leftinfo.size + rightinfo.size );
    if (leftinfo.isBST && rightinfo.isBST && leftinfo.max < root->data && rightinfo.min >root->data ) // these are condition of BST
    {
        curr.min = min(leftinfo.min, min(rightinfo.min, root->data));
        curr.max = max(rightinfo.max, max(leftinfo.max, root->data));
        curr.ans = curr.size;
        curr.isBST = true;
        return curr;
    }
    //else
    curr.ans = max(leftinfo.ans, rightinfo.ans);
    curr.isBST = false;
    return curr;
}

main()
{
    node *root = new node(15);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(5);
    /*15
     / \
    20   30
   / 
  5   
  */
  cout<<"The size of largest BST in the tree : "<<LargestBST(root).ans<<endl;
    return 0;
}