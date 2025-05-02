/*958. Check Completeness of a Binary Tree
Solved
Medium
Topics
Companies
Given the root of a binary tree, determine if it is a complete binary tree.

In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.



Example 1:


Input: root = [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.*/

// Code:-
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool isCompleteBT(TreeNode *root, int i, int nodeCount)
    {
        if (root == NULL)
            return true;
        if (i >= nodeCount)
            return false;

        return (isCompleteBT(root->left, 2 * i + 1, nodeCount) && isCompleteBT(root->right, 2 * i + 2, nodeCount));
    }
    int countNode(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int ans = 1 + countNode(root->left) + countNode(root->right);

        return ans;
    }
    bool isCompleteTree(TreeNode *root)
    {
        int index = 0;
        int totalNodes = countNode(root);
        return isCompleteBT(root, index, totalNodes);
    }
};

// prob link:-https://leetcode.com/problems/check-completeness-of-a-binary-tree/