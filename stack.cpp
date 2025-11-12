#include<stdio.h>
#include<conio.h>
#include<iostream>
#define max 5
using namespace std;
struct stack
{
    int data[max];
    int top;
};
stack s,*p;
void init()
{
    p=&s; 
    p->top=-1;
}
int  empty()
{
    if(p->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int full()
{
    if(p->top==max-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push()
{
    int x;
    if(full()) return;
    cout<<"enter data to push:-";
    cin>>x;
    p->top++;
    p->data[p->top]=x;  //p->data[0]=10; first push operation perform
            
}
int pop()
{
    int x;
    if(empty()) return 1;
    x=p->data[p->top];  //x=p->data[2]; first pop operation perform
    p->top--;
    return x;
}
int main()
{
    init();
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
