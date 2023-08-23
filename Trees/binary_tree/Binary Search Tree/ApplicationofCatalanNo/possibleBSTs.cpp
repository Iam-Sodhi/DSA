#include <iostream>
#include <vector>
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
vector<node *> buildtrees(int start, int end)
{
    vector<node *> trees;
    if (start > end)
    {
        trees.push_back(NULL);
        return trees;
    }

    for (int i = start; i <= end; i++)
    {
        vector<node*> leftsubtrees = buildtrees(start, i - 1);
        vector<node*> rightsubtrees = buildtrees(i + 1, end);
        for (int j = 0; j < leftsubtrees.size(); j++)
        {
            node *Left = leftsubtrees[j];

            for (int k = 0; k < rightsubtrees.size(); k++)
            {
                node *Right = rightsubtrees[k];
                node *root = new node(i);
                root->left = Left;
                root->right = Right;
                trees.push_back(root);
            }
        }
    }
    return trees;
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
int main()
{
  vector<node*> totalTress=buildtrees(1,3);
    for (int i = 0; i < totalTress.size(); i++)
    {   cout<<i+1<<" -> ";
        preorder(totalTress[i]);
        cout<<endl;
    }
    
    return 0;
}