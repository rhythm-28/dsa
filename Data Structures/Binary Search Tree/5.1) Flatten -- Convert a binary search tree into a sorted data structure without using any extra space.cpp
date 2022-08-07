// Flatten -- Convert a binary search tree into a sorted data structure without using any extra space 

// We did this by converting binary search tree into linked list (by changing connection of nodes)

#include<iostream>
#include<queue>
#include<utility>
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

node* insert_in_bst(node* root,int d)
{
    if(root==NULL)
    return new node(d);
    
    if(d<=root->data)
    root->left=insert_in_bst(root->left,d);

    else
    root->right=insert_in_bst(root->right,d);

    return root;
}

node* create_tree()
{
    int d;
    cin>>d;

    node* root=NULL;
    while(d!=-1)
    {
        root=insert_in_bst(root,d);
        cin>>d;
    }
    return root;
}

pair<node*,node*> flatten(node* root)
{
    // to store head and tail of linked list
    pair<node*,node*> p;

    // if tree is empty
    if(root==NULL)
    {
        p.first=NULL;
        p.second=NULL;
        return p;
    }

    // leaf node
    if(root->left==NULL && root->right==NULL)
    {
        p.first=root;
        p.second=root;
        return p;
    }

    // one node on left side
    if(root->left!=NULL && root->right==NULL)
    {
        pair<node*,node*> a=flatten(root->left);

        a.second->left=root;

        p.first=a.first;
        p.second=root;
        return p;
    }

    // one node on right side
    if(root->left==NULL && root->right!=NULL)
    {
        pair<node*,node*> b=flatten(root->right);

        root->left=b.first;

        p.first=root;
        p.second=b.second;
        return p;
    }

    // nodes on both side
    pair<node*,node*> a=flatten(root->left);
    pair<node*,node*> b=flatten(root->right);

    a.second->left=root;
    root->left=b.first;

    p.first=a.first;
    p.second=b.second;
    return p;
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



int main()
{
    node* root=create_tree();
    cout<<endl;
    print(root);
    cout<<endl;
    node* head=flatten(root).first;
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->left;
    }
    return 0;
}