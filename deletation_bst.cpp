#include <iostream>
using namespace std;
struct bst
{
    int data;
    bst *left, *right;
};
bst *root, *temp, *ttemp, *p,*s;
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
void in(bst *p)
{
    if (p != NULL)
    {
        in(p->left);
        cout << p->data<<"\n";
        in(p->right);
    }
}
void del(int x)
{
    temp = root;
    while (temp -> data !=x)
    {
        ttemp=temp;
        if (temp->data > x)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    if(temp->left != NULL && temp->right != NULL)
    {
        s=temp->right;
        while(s->left !=NULL)
        {
            ttemp=s;
            s=s->left;
        }
        temp->data =s->data;
        temp=s;
    }
    else if(temp->left == NULL && temp->right != NULL)
    {
        if(ttemp->left == temp)
        {
            ttemp->left = temp->right;
        }
        else
        {
            ttemp->right = temp->right; 
        }
    }
    else if(temp->left != NULL && temp->right == NULL)
    {
        if(ttemp->left == temp)
        {
            ttemp->left = temp->left;
        }
        else
        {
            ttemp->right = temp->left;
        }
    }
    else
    {
        if(ttemp->left == temp)
        {
            ttemp->left = NULL;
        }
        else
        {
            ttemp->right = NULL;
        }
    }
    temp->right = temp->left = NULL;
    delete temp;
}
int main()
{
    init();
    int c, n, i, a;
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
    cout<<"enter data to delete from bst:-";
    cin>>c;
    cout<<"inorder before deletion\n";
    in(root);
    del(c);
    cout<<"inorder after deletion\n";
    in(root);
}    