// Find successor and predecessor of given node

#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *insert_in_bst(node *root, int d)
{
    if (root == NULL)
        return new node(d);

    if (d <= root->data)
        root->left = insert_in_bst(root->left, d);

    else
        root->right = insert_in_bst(root->right, d);

    return root;
}

node *create_tree()
{
    int d;
    cin >> d;

    node *root = NULL;
    while (d != -1)
    {
        root = insert_in_bst(root, d);
        cin >> d;
    }
    return root;
}

void print(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    node *a;
    while (!q.empty())
    {
        a = q.front();

        if (a == NULL)
        {
            cout << endl;
            q.pop();

            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            // pop
            q.pop();

            // print
            cout << a->data << " ";

            // push children
            if (a->left != NULL)
                q.push(a->left);

            if (a->right != NULL)
                q.push(a->right);
        }
    }
}

void findPreSuc(node *root, node *&pre, node *&suc, int key)
{
    // for successor
    node *ans = NULL;
    node *temp = root;
    while (root != NULL)
    {
        if (root->data > key)
        {
            ans = root;
            root = root->left;
        }
        else
            root = root->right;
    }
    suc = ans;

    // for predecessor
    ans = NULL;
    root = temp;
    while (root != NULL)
    {
        if (root->data < key)
        {
            ans = root;
            root = root->right;
        }
        else
            root = root->left;
    }
    pre = ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    node *root = create_tree();
    int key;
    cin >> key;
    print(root);
    cout << endl;
    node *pre = NULL;
    node *suc = NULL;
    findPreSuc(root, pre, suc, key);
    if (pre != NULL)
        cout << pre->data;
    else
        cout << -1;
    cout << " ";
    if (suc != NULL)
        cout << suc->data;
    else
        cout << -1;
    return 0;
}