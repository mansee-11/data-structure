#include <iostream>
using namespace std;
struct bst
{
    int data;
    bst *left, *right;
};
bst *root, *temp, *ttemp, *p;
void init()
{
    root = temp = ttemp = p = NULL;
}
void create_root(int x)
{
    root = new bst;
    root->data = x;
    root->left = root->right = NULL;
}
void add_node(int x)
{
    temp = root;
    while (temp != NULL)
    {
        ttemp = temp;
        if (temp->data > x)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    p = new bst;
    p->data = x;
    p->left = p->right = NULL;
    if (ttemp->data > x)
    {
        ttemp->left = p;
    }
    else
    {
        ttemp->right = p;
    }
}
void level_no(int x)
{
    int level=0;
    temp = root;
    while (temp -> data !=x)
    {
        if (temp->data > x)
        {
            level++;
            temp = temp->left;
        }
        else
        {
            level++;
            temp = temp->right;
        }
    }
    cout<<"level of given node is "<<level;
}
void in(bst *p)
{
    if (p != NULL)
    {
        in(p->left);
        cout << p->data<<"\n";
        in(p->right);
    }
}
void pre(bst *p)
{
    if (p != NULL)
    {
        cout << p->data<<"\n";
        pre(p->left);
        pre(p->right);
    }
}
void post(bst *p)
{
    if (p != NULL)
    {
        post(p->left);
        post(p->right);
        cout << p->data<<"\n";
    }
}
int main()
{
    init();
    int c, n, i, a, j = 1;
    cout << "enter no of data you want to insert:- ";
    cin >> n;
    cout << "enter data one by one:- \n";
    cin >> a;
    create_root(a);
    for (i = 0; i < n - 1; i++)
    {
        cin >> a;
        add_node(a);
    }
    while (j == 1)
    {
        cout << "\n1-add data\n2-inorder treversing\n3-preorder treversing";
        cout << "\n4-postorder treversing\n5-to find level of node\n6-exit";
        cout << "\nEnter your choice:- ";
        cin >> c;
        if (c == 1)
        {
            cout << "enter data to add:-";
            cin >> a;
            add_node(a);
        }
        else if (c == 2)
        {
            in(root);
        }
        else if (c == 3)
        {
            pre(root);
        }
        else if (c == 4)
        {
            post(root);
        }
        else if(c==5)
        {
            j=0;
        }
        else
        {
            cout << "invalid input";
        }
    }
}