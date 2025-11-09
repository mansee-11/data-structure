#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next,*prev;
};
node*first,*temp,*ttemp,*p;
void init()
{
    first=ttemp=temp=p=NULL;
}
void create_first()
{
    first= new node;
    cin>>first->data;
    first->prev=first->next=first;
}
void add_node()
{
    temp=first->prev;
    ttemp=new node;
    cin>>ttemp->data;
    ttemp->next=first;
    ttemp->prev=temp;
    temp->next=ttemp;
    first->prev=ttemp;
}
void disp()
{
    ttemp=first;
    do
    {
        cout<<ttemp->data<<"\n";
        ttemp=ttemp->next;
    }
    while(ttemp!=first);
}
void add_before_first()
{
    temp=first;
    ttemp=new node;
    cout<<"enter data to insert:-";
    cin>>ttemp->data;
    ttemp->prev=temp->prev;
    temp->prev->next=ttemp;
    temp->prev=ttemp;
    ttemp->next=temp;
    first=ttemp;
}
void del_last()
{
    temp=first->prev;
    ttemp=temp->prev;
    ttemp->next=first;
    first->prev=ttemp;
    temp->next=temp->prev=NULL;
    delete temp;
}
void del_first()
{
    temp=first;
    ttemp=first->prev;
    ttemp->next=temp->next;
    first=temp->next;
    temp->next->prev=ttemp;
    temp->next=temp->prev=NULL;
    delete temp;
}
void swap_12()
{
    temp=first;
    ttemp=first->prev;
    p=temp->next;
    ttemp->next=p;
    p->prev=ttemp;
    temp->next=p->next;
    temp->next->prev=temp;
    temp->prev=p;
    p->next=temp;
}
void swap_1st_last()
{
    temp=first;
    ttemp=first->prev;
    p=ttemp->prev;
    p->next=temp;
    ttemp->prev=temp;
    ttemp->next=temp->next;
    temp->next=ttemp;
    temp->prev=p;
    first=ttemp;
}
void swap_l_sl()
{
    temp=first->prev;
    ttemp=temp->prev;
    temp->prev=ttemp->prev;
    temp->prev->next=temp;
    temp->next=ttemp;
    ttemp->prev=temp;
    ttemp->next=first;
    first->prev=ttemp;
}
int main()
{
    int n,i,j=1;
    init();
    cout<<"To create link list enter no of elements:-";
    cin>>n;
    cout<<"enter element of link list one by one:-";
    create_first();
    for(i=0;i<n-1;i++)
    {
        add_node();
    }
    while(j==1)
    {
        cout<<"1-add new element\n2-display\n3-add before first\n";
        cout<<"4-del first\n5-del last\n";
        cout<<"6-swap 1st 2nd\n7-swap 1st last\n8-swap last second last\n9-enter any no. to exit\n";
        cout<<"enter your choice:-";
        cin>>i;
        switch(i)
        {
            case 1:
            {
                cout<<"enter data to insert:-";
                add_node();
                break;
            }
            case 2:
            {
                disp();
                break;
            }
            case 3:
            {
                add_before_first();
                break;
            }
            case 4:
            {
                del_first();
                break;
            }
            case 5:
            {
                del_last();
                break;
            }
            case 6:
            {
                swap_12();
                break;
            }
            case 7:
            {
                swap_1st_last();
                break;
            }
            case 8:
            {
                swap_l_sl();
                break;
            }
            default: j=0;
        }
    }
}