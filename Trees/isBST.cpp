int isBST(Node*root){
    Node*prev=nullptr;
    if(root!=nullptr){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=nullptr && root->data<=prev->data){
            return 0;
        }
        prev=root;
        return isBSt(root->right);
    }else{
        return 1;
    }
}