
int childrenSumParent(TreeNode*root){
    if(root==nullptr || (root->left==nullptr && root->right==nullptr)){
        return 1;
    }

    int left_val=0;
    int right_val=0;

    if(root->left!=nullptr){
        left_val=root->left->val;
    }
    if(root->right!=nullptr){
       right_val=root->right->val;
    }

    if((root->val==left_val+right_val) && childrenSumParent(root->left) && childrenSumParent(root->right)){
        return 1;
    }
    return 0;
}