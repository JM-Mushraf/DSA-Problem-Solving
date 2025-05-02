/*
Is Binary Tree Heap
Difficulty: MediumAccuracy: 34.41%Submissions: 129K+Points: 4
You are given a binary tree, and the task is to determine whether it satisfies the properties of a max-heap.

A binary tree is considered a max-heap if it satisfies the following conditions:

Completeness: Every level of the tree, except possibly the last, is completely filled, and all nodes are as far left as possible.
Max-Heap Property: The value of each node is greater than or equal to the values of its children.
Examples:

Input: root[] = [97, 46, 37, 12, 3, 7, 31, 6, 9]

Output: true
Explanation: The tree is complete and satisfies the max-heap property.
*/

// code:-
class Solution
{
public:
    bool isCompleteBT(Node *root, int i, int nodeCount)
    {
        if (root == NULL)
            return true;
        if (i >= nodeCount)
            return false;

        return (isCompleteBT(root->left, 2 * i + 1, nodeCount) && isCompleteBT(root->right, 2 * i + 2, nodeCount));
    }
    bool isMaxHeap(Node *root)
    {
        if (root->left == NULL && root->right == NULL)
        {
            return true;
        }
        if (root->right == NULL)
        {
            return (root->data > root->left->data);
        }
        return (root->data > root->left->data && root->data > root->right->data && isMaxHeap(root->left) && isMaxHeap(root->right));
    }
    int countNode(Node *root)
    {
        if (root == NULL)
            return 0;

        int ans = 1 + countNode(root->left) + countNode(root->right);

        return ans;
    }
    bool isHeap(Node *tree)
    {
        // code here
        int index = 0;
        int totalNodes = countNode(tree);
        if (isCompleteBT(tree, index, totalNodes) && isMaxHeap(tree))
            return true;
        return false;
    }
};

// prob link:-https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1