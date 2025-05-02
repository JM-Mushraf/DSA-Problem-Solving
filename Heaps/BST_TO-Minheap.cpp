/*Given a binary search tree which is also a complete binary tree. The problem is to convert the given BST into a Min Heap with the condition that all the values in the left subtree of a node should be less than all the values in the right subtree of the node. This condition is applied to all the nodes, in the resultant converted Min Heap. */


#include<iostream>
#include <vector>
using namespace std;
class Node{
    public:
        int data;
        Node*left;
        Node*right;

        Node(int val){
            data=val;
            left=right=NULL;
        }
};

void inOrder(Node*root, vector<int>&in){
    if(root==NULL)return;

    inOrder(root->left,in);
    in.push_back(root->data);
    inOrder(root->right,in);
}
void preOrder(Node*root,vector<int>&in,int &ind){
    if(root==NULL) return;
    root->data=in[ind++];
    preOrder(root->left,in,ind);
    preOrder(root->right,in,ind);
}
void convertBST_To_MinHeap(Node*root){
    vector<int>in;
    // Step 1: Perform inorder traversal 
    // to store values in sorted order
    inOrder(root,in);
    int ind=0;
    // Step 2: Perform preorder traversal and 
    // fill nodes with inorder values
    preOrder(root,in,ind);
}

void preorderPrint(Node* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " "; 
    preorderPrint(root->left); 
    preorderPrint(root->right); 
}
int main()
{
    /* Constructing the Binary Search Tree (BST)
              4
            /   \
           2     6
          / \   / \
         1   3 5   7  */
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
    convertBST_To_MinHeap(root);
    preorderPrint(root);
    return 0;
}