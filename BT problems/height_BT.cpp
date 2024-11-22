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
    struct node *createNode(int data)
    {
        struct node *root = new struct node();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        return root;
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
    return 0;
}