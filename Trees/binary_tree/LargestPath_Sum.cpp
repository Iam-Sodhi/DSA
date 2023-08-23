#include <iostream>
#include <queue>
using namespace std;
// Find the largest sum that any path can have
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
int maxSumUtil(node *root, int &ans)
{
    if (root == NULL)
    {
        return 0;
    }
    int maxSumNode;
    int left = maxSumUtil(root->left, ans);
    int right = maxSumUtil(root->right, ans);
    maxSumNode = max(max(root->data, root->data + left + right), max(root->data + left, root->data + right));
    ans = max(ans, maxSumNode); // to update the answer

    int maxSinglepathSum = max(root->data, max(root->data + left, root->data + right));
    return maxSinglepathSum;
}
int MaximumPath_Sum(node *root)
{
    int ans = INT8_MIN;
    maxSumUtil(root, ans);
    return ans;
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
  cout<<MaximumPath_Sum(root);
    return 0;
}