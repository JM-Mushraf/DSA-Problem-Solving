#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* deleteNode(Node* root,int key){
    if(root==nullptr){
        return nullptr;
    }

    if(key < root->data){
        root->left=deleteNode(root->left,key);
    }
    else if(key > root->data){
        root->right=deleteNode(root->right,key);
    }
    else{
        // case1
        if(root->left==nullptr && root->right==nullptr){
            delete root;
            return nullptr;
        }
        //case 2
        else if(root->right==nullptr){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        else if(root->left==nullptr){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        //case 3
        else{
            //we'll find the in-order successor
            Node* temp=root->right;
            while(temp->left!=nullptr){
                temp=temp->left;
            }
            root->data=temp->data;
            root->right = deleteNode(root->right,temp->data);
        }
    }
    return root;
}
void inorder(Node* root){
    if(root!=nullptr){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
int main()
{
    Node *root=new Node(5);
    Node *p1=new Node(3);
    Node *p2=new Node(6);
    Node *p3=new Node(1);
    Node *p4=new Node(4);
    Node *p5=new Node(7);
    Node *p6=new Node(2);
    root->left=p1;
    root->right=p2;
    p1->left=p3;
    p1->right=p4;
    p2->right=p5;
    p3->right=p6;

    inorder(root);
    cout<<endl;
    deleteNode(root, 3);
    inorder(root);

    return 0;
}