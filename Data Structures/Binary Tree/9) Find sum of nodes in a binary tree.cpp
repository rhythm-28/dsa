// Find sum of nodes in a binary tree

#include<iostream>
#include<queue>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;
    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};

node* create_tree()
{
    int d;
    cin>>d;
    if(d==-1)
    return NULL;
    node* root = new node(d);
    root->left=create_tree();
    root->right=create_tree();
    return root;
}

void print(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    node* a;
    while(!q.empty())
    {   
        a=q.front();
        
        if(a==NULL)
        {
            cout<<endl;
            q.pop();

            if(!q.empty())
            q.push(NULL);
        }
        else
        {
            // pop 
            q.pop();

            // print
            cout<<a->data<<" "; 

            // push children
            if(a->left!=NULL)
            q.push(a->left);

            if(a->right!=NULL)
            q.push(a->right);
        }
    }
}

int sum(node* root)
{
    if(root==NULL)
    return 0;

    int left=sum(root->left);
    int right=sum(root->right);

    return root->data+left+right;
}

int main()
{
    node* root=create_tree();
    print(root);
    cout<<"sum of nodes="<<sum(root);
    return 0;
}