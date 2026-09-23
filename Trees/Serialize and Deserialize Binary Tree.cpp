/*

Code
Testcase
Testcase
Test Result
297. Serialize and Deserialize Binary Tree
Solved
Hard
Topics
premium lock icon
Companies
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

 

Example 1:


Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
Example 2:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-1000 <= Node.val <= 1000
*/

// code:
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "";
        string res;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode*node=q.front();
            q.pop();
            if(node==nullptr){
                res+="#,";
            }else{
                res+=to_string(node->val)+",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())return nullptr;

        stringstream s(data);
        queue<TreeNode*>q;

        string str;
        getline(s,str,',');

        TreeNode*node=new TreeNode(stoi(str));
        q.push(node);

        while(!q.empty()){
            TreeNode*root=q.front();
            q.pop();

            //for left
            getline(s,str,',');
            if(str!="#"){
                root->left=new TreeNode(stoi(str));
                q.push(root->left);
            }

            //for right
            getline(s,str,',');
            if(str!="#"){
                root->right=new TreeNode(stoi(str));
                q.push(root->right);
            }
        }
        return node;
    }
};
