#include <bits/stdc++.h>
using namespace std;
//this is part 2
// Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

//here we need to return the different trees not just the number of unique trees (see carefully & remember the pattern)

// vector<TreeNode *> solveMem(int st, int end, map<pair<int, int>, vector<TreeNode *>> &dp)
// {
//     if (st > end)
//         return {NULL};
//     if (st == end)
//     {
//         return {new TreeNode(st)};
//     }
//     if (dp.count({st, end}))
//         return dp[{st, end}];

//     vector<TreeNode *> ans;
//     for (int i = st; i <= end; i++)
//     {
//         vector<TreeNode *> l = solveMem(st, i - 1, dp);
//         vector<TreeNode *> r = solveMem(i + 1, end, dp);

//         // now let's connect the diff left and right subtrees with the root
//         for (TreeNode *le : l)
//         {
//             for (TreeNode *ri : r)
//             {
//                 TreeNode *newNode = new TreeNode(i);
//                 newNode->left = le;
//                 newNode->right = ri;
//                 ans.push_back(newNode);
//             }
//         }
//     }
//     return dp[{st, end}] = ans;
// }
// vector<TreeNode *> generateTrees(int n)
// {
//     map<pair<int, int>, vector<TreeNode *>> dp;
//     return solveMem(1, n, dp);
// }
int main()
{
    return 0;
}