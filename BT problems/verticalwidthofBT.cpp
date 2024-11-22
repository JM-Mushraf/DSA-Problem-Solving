unorder_set<int> st;
void inorderutil(TreeNode*root,int hd)
{
    if(root!=NULL){
        inorderutil(root->left,hd-1);
        st.insert(hd);
        inorderutil(root->right,hd+1);
    }
}
int verticalWidth(TreeNode*root){
    st.clear();
    inorderutil(root,0);
    return st.size();
}