#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *root = new struct node();
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void preOrder(struct node *root)
{
    if (root)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct node *root)
{
    if (root)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void postOrder(struct node *root)
{
    if (root)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

vector<int> iterativePreorder(struct node *root)
{
    vector<int> preorder;
    if (root==NULL)
        return preorder;
    stack<struct node *> st;
    st.push(root);
    while (!st.empty())
    {
        root = st.top();
        st.pop();
        preorder.push_back(root->data);
        if (root->right != NULL)
        {
            st.push(root->right);
        }
        if (root->left != NULL)
        {
            st.push(root->left);
        }
    }
    return preorder;
}

vector<int> iterativeInorder(struct node*root){
    vector<int> inorder;
    struct node*node=root;
    stack<struct node*>st;
    while(true){
        if(node!=NULL){
            st.push(node);
            node=node->left;
        }
        else{
            if(st.empty()){
                break;
            }
            node=st.top();
            st.pop();
            inorder.push_back(node->data);
            node=node->right;
        }
    }
    return inorder;
}

vector<int> iterativePostorder2Stack(struct node*root){
    vector<int>postorder;
    if(root==NULL)return postorder;
    stack<struct node*>st1,st2;
    st1.push(root);
    while(!st1.empty()){
        root=st1.top();
        st1.pop();
        st2.push(root);
        if(root->left!=NULL){
            st1.push(root->left);
        }
        if(root->right!=NULL){
            st1.push(root->right);
        }
    }
    while(!st2.empty()){
        postorder.push_back(st2.top()->data);
        st2.pop();
    }
    return postorder;
}

vector<int> iterativePostorder1stack(struct node*root)
{
    vector<int>postorder;
    if(root==NULL) return postorder;
    stack<struct node*>st;
    struct node*curr=root;
    struct node*temp;
    // st.push(curr);
    while(curr!=NULL || !st.empty())
    {
        if(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }
        else{
            temp=st.top()->right;
            if(temp==NULL){
                temp=st.top();
                st.pop();
                postorder.push_back(temp->data);
                while(!st.empty() && temp==st.top()->right)
                {
                    temp=st.top();
                    st.pop();
                    postorder.push_back(temp->data);
                }
            }
            else{
                curr=temp;
            }
        }
    }
    return postorder;
}

vector<vector<int>> levelOrder(struct node *root)
{
    vector<vector<int>> res;
    if (root == NULL)
        return res;

    queue<struct node *> q1;
    q1.push(root);

    while (!q1.empty())
    {
        int levelSize = q1.size(); // Get the number of nodes at the current level
        vector<int> level;

        for (int i = 0; i < levelSize; i++)
        {
            struct node *Node = q1.front();
            q1.pop();

            if (Node->left != NULL)
                q1.push(Node->left);
            if (Node->right != NULL)
                q1.push(Node->right);

            level.push_back(Node->data);
        }
        res.push_back(level);
    }

    return res;
}
int main()
{
    struct node *root = createNode(7);
    struct node *a = createNode(11);
    struct node *b = createNode(2);
    struct node *c = createNode(7);
    struct node *d = createNode(9);

    root->left = a;
    root->right = b;

    a->left = c;
    b->right = d;

    cout << "Preorder Traversal\n";
    preOrder(root);
    cout << "\nInorder Traversal\n";
    inOrder(root);
    cout << "\nPostorder Traversal\n";
    postOrder(root);
    vector<vector<int>> res = levelOrder(root);
    cout << endl;
    cout << "Level order Traversal" << endl;
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        { // Corrected: res[i].size
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Preorder Traversal\n";
    preOrder(root);
    cout<<endl;
    cout << "iterative preorder traversal" << endl;
    vector<int> res1 = iterativePreorder(root);
    for (int i = 0; i < res1.size(); i++)
    {
        cout << res1[i] << " ";
    }

    cout << "\nInorder Traversal\n";
    inOrder(root);
    cout<<endl;
    cout << "\niterative Inorder Traversal\n";
    vector<int> res2 = iterativeInorder(root);
    for (int i = 0; i < res2.size(); i++)
    {
        cout << res2[i] << " ";
    }


     cout << "\nPostorder Traversal\n";
    postOrder(root);
    cout<<endl;
    cout << "iterative Postorder Traversal using 1 stacks\n";
    vector<int> res3 = iterativePostorder1stack(root);
    for (int i = 0; i < res3.size(); i++)
    {
        cout << res3[i] << " ";
    }
    cout<<endl;
    cout << "iterative Postorder Traversal using 2 stacks\n";
    vector<int> res4 = iterativePostorder2Stack(root);
    for (int i = 0; i < res4.size(); i++)
    {
        cout << res4[i] << " ";
    }
    return 0;
}
