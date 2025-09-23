#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
class tree
{
public:
    struct node *createNode(int data)
    {
        struct node *root = new struct node();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    int heightOfBt(struct node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        else
        {
            return max(heightOfBt(root->left), heightOfBt(root->right)) + 1;
        }
    }
    void inorderUtil(struct node *root,bool &ans){
        if(root!=NULL){
            inorderUtil(root->left,ans);

            int lh=heightOfBt(root->left);
            int rh=heightOfBt(root->right);

            if(abs(lh-rh)>1){
                ans=ans&&false;
            }

            inorderUtil(root->right,ans);
        }
    }
    bool isBalanced(struct node*root){
        bool ans=true;
        inorderUtil(root,ans);
        return ans;
    }
};
int main()
{
    tree t1;
    struct node *root = t1.createNode(7);
    struct node *a = t1.createNode(11);
    struct node *b = t1.createNode(2);
    struct node *c = t1.createNode(7);
    struct node *d = t1.createNode(9);

    root->left = a;
    root->right = b;

    a->left = c;
    b->right = d;

    int height=t1.heightOfBt(root);
    cout<<"Height of Binary Tree is:"<<height<<endl;

    bool res=t1.isBalanced(root);
    if(res){
        cout<<"Tree is balanced"<<endl;
    }
    else{
        cout<<"Tree is balanced"<<endl;
    }
    return 0;
}