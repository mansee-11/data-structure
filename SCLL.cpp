#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
node *temp,*first,*ttemp,*p;
void init() 
{
    first = temp = ttemp = NULL;
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
void disp()     //this is not possible without do while loop
{
    temp = first;
    do
    {
        cout<<temp -> data<<"\n";
        temp=temp->next;
    }   
    while(temp!=first);
}
void add_before_first()
{
    temp=first;
    while(temp->next!=first)
    {
        temp=temp->next;
    }
    p=new node;
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
void swap_12()
{
    temp=first;
    ttemp=temp->next;
    p=first;
    while(p->next!=first)
    {
        p=p->next;
    }
    temp->next=ttemp->next;
    ttemp->next=temp;
    p->next=ttemp;
    first=ttemp;

}
void swap_lsl()
{
    ttemp=first;
    while(ttemp->next->next!=first)
    {
        p=ttemp;
        ttemp=ttemp->next;
    }
    temp=ttemp->next;
    p->next=temp;
    ttemp->next=first;
    temp->next=ttemp;
}
void swap_fl()
{
    temp=first;
}
int main()
{
    init();
    create_first();
    add_node();
    add_node();
    add_node();
    //del_first();
    //del_last();
    //swap_12();
    swap_lsl();
    disp();
}
