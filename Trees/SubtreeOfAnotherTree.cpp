// 572. Subtree of Another Tree

// Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.



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
class Solution {
public:
    bool ans =false;
    bool match(TreeNode* root, TreeNode* subRoot){
        if(root!=NULL && subRoot!=NULL){
            bool a=match(root->left,subRoot->left);
            bool b=match(root->right,subRoot->right);

            if((root->val==subRoot->val) && a && b){
                return true;
            }
            else{
                return false;
            }
        }
        else if(root==NULL && subRoot==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    void inOrder(TreeNode* root, TreeNode* subRoot){
        if(root!=NULL){
            inOrder(root->left,subRoot);
            bool x=match(root,subRoot);
            if(x){
                ans=x;
            }
            inOrder(root->right,subRoot);
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        inOrder(root,subRoot);
        return ans;
    }
};