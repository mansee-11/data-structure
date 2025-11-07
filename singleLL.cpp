#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *first, *temp, *ttemp, *p;
void init()
{
    first = temp = ttemp = NULL;
}
void create_first()
{
    first = new node;
    first->next = NULL;
    cin >> first->data;
}
void add_node()
{
    temp = first;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    ttemp = new node;
    ttemp->next = NULL;
    temp->next = ttemp;
    cin >> ttemp->data;
}

void disp()
{
    temp = first;
    while (temp->next!= NULL)
    {
        cout << temp->data << "\n";
        temp = temp->next;
    }
    cout << temp->data << "\n";
}
void del_first()
{
    temp = first;
    first = first->next;
    temp->next = NULL;
    delete temp;
}
void del_after(int x)
{
    temp = first;
    while (temp->data != x)
    {
        temp = temp->next;     
    }
    ttemp = temp->next;
    p = ttemp->next;
    temp->next = p;
    ttemp->next = NULL;
    delete ttemp;
}

void del_before(int x)
{

    temp = first;
    while (temp->next->data != x)
    {
        ttemp = temp;
        temp = temp->next;
    }
    p = temp->next;
    ttemp->next = p;
    temp->next = NULL;
    delete temp;

}
void del_secondlast()
{
    temp = first;
    while (temp->next->next != NULL)
    {
        ttemp = temp;
        temp = temp->next;
    }
    p = temp->next;
    temp->next = NULL;
    ttemp->next = p;
    delete temp;
}
void swap12()
{
    temp = first;
    ttemp = temp->next;
    p = ttemp->next;
    ttemp->next = temp;
    temp->next = p;
    first = ttemp;
}
void swap_1_last()
{
    temp = first;
    while (temp->next != NULL)
    {
        ttemp = temp;
        temp = temp->next;
    }
    p = first->next;
    ttemp->next = first;
    first->next = NULL;
    temp->next = p;
    first = temp;
}
void add_after(int x, int y)
{
    temp = first;
    while (temp->data != x)
    {
        temp = temp->next;
    }
    ttemp = temp->next;
    p = new node;
    p->data = y;
    p->next = temp;
    temp->next = p;
}

void add_before(int x, int y)
{
    temp = first;
    while (temp->data != x)
    {
        ttemp = temp;
        temp = temp->next;
    }
    p = new node;
    p->data = y;
    p->next = temp;
    ttemp->next;
}

void add_before_first(int x)
{
    temp = new node;
    temp->data = x;
    temp->next = first;
    first = temp;
}

void add_before_last(int x)
{
    temp = first;
    while (temp->next != NULL)
    {
        ttemp = temp;
        temp = temp->next;
    }
    p = new node;
    p->data = x;
    p->next = temp;
    ttemp->next = p;
}
void swapmn(int x, int y)
{
    temp = first;
    while (temp->next->data != x)
    {
        temp = temp->next;
    }
    ttemp = first;
    while (ttemp->next->data != y)
    {
        ttemp = ttemp->next;
    }
    p = temp->next->next;
    temp->next->next = ttemp->next->next;
    ttemp->next->next = p;
    p = temp->next;
    temp->next = ttemp->next;
    ttemp->next = p;
}
void reverse()
{
    temp=first;
    p=NULL;
    ttemp=NULL;
    while(temp!=NULL)
    {
        ttemp=temp->next;   //saving next value in ttemp
        temp->next=p;       //changing next value
        p=temp;             //saving prev value in p
        temp=ttemp;         //going on next
    }
}
int main()
{
    int i, a, b, j=1;
    init();
    cout << "enter element one by one to create link list";
    create_first();
    for (i = 0; i < 4; i++)
    {
        add_node();
    }
    while (j==1)
    {
        cout << "1- add node after given data\n2-add before 1st node \n3-add before given data\n4-add before last node";
        cout << "5-del before given data\n6-del after given data\n7-delfirst node\n8-del secondlast node ";
        cout << "9-swap 1st and 2nd\n10-swap 1st and last\n11-swap mth and nth term\n";
        cout<<"12-display\n13-reverse link list\n14 exit\n";
        cout << "enter your choice from the menu:-";
        cin >> i;
        switch (i)
        {
        case 1:
        {
            cout << "input data to add after it and theen enter data to be added";
            cin >> a >> b;
            add_after(a, b);
            break;
        }
        case 2:
        {
            cout << "enter data to add ";
            cin >> a;
            add_before_first(a);
            break;
        }
        case 3:
        {
            cout << "enter data to add before then enter data to add";
            cin >> a >> b;
            add_before(a, b);
            break;
        }
        case 4:
        {
            cout << "enter element to add";
            add_before_last(a);
            break;
        }
        case 5:
        {
            cout << "enter data to del before it ";
            cin >> a;
            del_before(a);
            break;
        }
        case 6:
        {
            cout << "enter data to del after it";
            cin >> a;
            del_after(a);
            break;
        }
        case 7:
        {
            del_first();
            break;
        }
        case 8:
        {
            del_secondlast();
        }
        case 9:
        {
            swap12();
            break;
        }
        case 10:
        {
            swap_1_last();
            break;
        }
        case 11:
        {
            cout << "enter both data to exchange position";
            cin >> a >> b;
            swapmn(a, b);
            break;
        }
        case 12:
        {
            disp();
            break;
        }
        case 13:
        {
            reverse();
            break;
        }
        default:
        {
            j = 0;
        }
        }
    }
}
