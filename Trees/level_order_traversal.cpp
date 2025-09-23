/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==nullptr)return res;

        queue<TreeNode *>q;
        q.push(root);

        while(!q.empty()){
            vector<int> level;

            for(int i=0;i<q.size();i++){
                TreeNode*node=q.front();
                q.pop();

                if(node->left!=nullptr)q.push(node->left);
                if(node->right!=nullptr)q.push(node->right);

                level.push_back(node->data);
            }
            res.push_back(level);
        }
        return res;
    }
};