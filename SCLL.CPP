#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *temp,*ttemp,*first,*p;
void init()
{
    first=temp=ttemp=p=NULL;
}
void create_first()
{
    first=new node;
    cin>>first->data;
    first->next=first;
}
void add_node()
{
    temp=first;
    while(temp->next!=first)
    {
        temp=temp->next;
    }
    ttemp=new node;
    cin>>ttemp->data;
    ttemp->next=first;
    temp->next=ttemp;
}
void disp()
{
    temp=first;
    do
    {
        cout<<temp->data<<"\n";
        temp=temp->next;
    } while (temp!=first);
}
void add_before_first()
{
    temp=first;
    while(temp->next!=first)
    {
        temp=temp->next;
    }
    p=new node;
    cout<<"enter data to add:-";
    cin>>p->data;
    p->next=first;
    temp->next=p;
    first=p;
}
void del_first()
{
    temp=first;
    while(temp->next!=first)
    {
        temp=temp->next;
    }
    ttemp=first;
    p=ttemp->next;
    temp->next=p;
    first=p;
    ttemp->next=NULL;
    delete ttemp;
}
void del_last()
{
    temp=first;
    while(temp->next!=first)
    {
        ttemp=temp;
        temp=temp->next;
    }
    ttemp->next=first;
    temp->next=NULL;
    delete temp;
}
void swap_L_SL()
{
    temp=first;
    while(temp->next->next!=first)
    {
        p=temp;
        temp=temp->next;
    }
    ttemp=temp->next;
    p->next=ttemp;
    temp->next=first;
    ttemp->next=temp;
}
int main()
{
    int n,i,j=1;
    init();
    cout<<"To create link list enter no of elements:-";
    cin>>n;
    cout<<"entr element of link list one by one:-";
    create_first();
    for(i=0;i<n-1;i++)
    {
        add_node();
    }
    while(j==1)
    {
        cout<<"1-add new node\n2-display\n3-add before first\n";
        cout<<"4-del first\n5-del last\n6-swap last Slast\n7-any no.to exit\n";
        cout<<"enter your choice:-";
        cin>>i;
        switch(i)
        {
            case 1:
            { 
                cout<<"enter data to add node:-";
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
                swap_L_SL();
                break;
            }
            defualt:j=0;
        }
    }
}