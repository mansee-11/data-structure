#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
struct stack
{
    int data;
    stack *next;
};
stack *top,*temp;
void init()
{
    top=temp=NULL;
}
void push()    //do like add before first
{
    int x;
    temp=new stack;
    if(temp==NULL) return;
    cout<<"enter data to push:-";
    cin>>x;
    temp->data=x;
    temp->next=top;
    top=temp;
}
int pop()           //do like del first
{
    int x;
    if(top==NULL)return -1;
    temp=top;
    x=temp->data;
    top=top->next;
    temp->next=NULL;
    delete temp;
    return x;
}
int main()
{
    init();
    int i,j=1,a;
    while(j==1)
    {
        cout<<"\n1-push in stack\n2-pop from stack\n3-any no to exit\n";
        cout<<"enter your choice:-";
        cin>>i;
        switch(i)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                cout<<"pooped element:- "<<pop();
                break;
            }
            default:
            {
                j=0;
            }
        }
    }
}