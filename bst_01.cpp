#include <iostream>
using namespace std;
struct bst
{
    int data,level;
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
    root->level=0;
    root->left = root->right = NULL;
}

void add_node(int x)
{
    int lv=0;
    temp = root;
    while (temp != NULL)
    {
        ttemp = temp;
        if (temp->data > x)
        {
            lv++;
            temp = temp->left;
        }
        else
        {
            lv++;
            temp = temp->right;
        }
    }
    p = new bst;
    p->data = x;
    p->level=lv;
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

void level_no(int x)
{
    temp = root;
    while (temp -> data !=x)
    {
        if (temp->data > x)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    cout<<"level of given node is "<<temp->level;
}

int width(bst *p,int lv)
{
    //in this only one statement will run from the 3 statement 
    if(p==NULL) //1st statement
    {
        return 0;
    }    
    if(p->level ==lv)   //2nd statement
    {
        return 1;
    }
    return width(p->left,lv)+width(p->right,lv);    //3rd statement(recursive call)
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
        cout << "\n1-add data\n";
        cout<<"2-inorder treversing\n";
        cout<<"3-preorder treversing\n";
        cout << "4-postorder treversing\n";
        cout<<"5-find level of node\n";
        cout<<"6-width of level\n";
        cout<<"7-any no to exit\n";
        cout << "Enter your choice:- ";
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
            cout<<"enter data to find level:- ";
            cin>>a;
            level_no(a);
        }
        else if(c==6)
        {
            cout<<"enter level to find width:- ";
            cin>>a;
            cout<<"width of given level:- "<<width(root,a);
        }
        else
        {
            j=0;
        }
    }
}