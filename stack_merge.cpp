#include<iostream>
using namespace std;
struct stack
{
    int data;
    stack *next;
};
stack *top,*temp,*top1,*top2;
void init()
{
    top=top1=top2=temp=NULL;
}
void push(int x)   
{
    temp=new stack;
    temp->data=x;
    temp->next=top;
    top=temp;
}
void push1()   
{
    int x;
    cin>>x;
    temp=new stack;
    temp->data=x;
    temp->next=top1;
    top1=temp;
}
void push2()   
{
    int x;
    cin>>x;
    temp=new stack;
    temp->data=x;
    temp->next=top2;
    top2=temp;
}
int pop1()
{
    int x;
    if(top1==NULL)return -1;
    temp=top1;
    x=temp->data;
    top1=top1->next;
    temp->next=NULL;
    delete temp;
    return x;
}
int pop2()
{
    int x;
    if(top2==NULL)return -1;
    temp=top2;
    x=temp->data;
    top2=top2->next;
    temp->next=NULL;
    delete temp;
    return x;
}
void disp()
{
    cout<<"data in merged stack:-"<<"\n";
    temp=top;
    do
    {
        cout<<temp->data<<"\n";
        temp=temp->next;
    }while(temp!=NULL);
}
int main()
{
    int n,i;
    init();
    cout<<"enter no of data in small stacks:- ";
    cin>>n;
    cout<<"enter data for stack 1:-"<<"\n";
    for(i=0;i<n;i++)
    {
        push1();
    }
    cout<<"enter data for stack 2:-"<<"\n";
    for(i=0;i<n;i++)
    {
        push2();
    }
    for(i=0;i<n;i++)
    {
        push(pop1());
        push(pop2());
    }
    disp();
}