Node*search(Node*root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    else if(key < root->data){
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }
}