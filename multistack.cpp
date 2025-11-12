#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
#define max 5
struct stack{
    int data[max];
    int topa,topb;
};
stack *p,s;
void init()
{
    p=&s;
    p->topa=-1;
    p->topb=max;
}
int empty_a()
{
    if(p->topa==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int empty_b()
{
    if(p->topb==max)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int full_ab()
{
    if(p->topa+1==p->topb)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push_a()
{
    int x;
    if(full_ab()) return;
    cout<<"enter data to push:- ";
    cin>>x;
    p->topa++;
    p->data[p->topa]=x;
}
void push_b()
{
    int x;
    if(full_ab()) return;
    cout<<"enter data to push:- ";
    cin>>x;
    p->topb++;
    p->data[p->topb]=x;
}
int pop_a()
{
    int x;
    if(empty_a()) return -1;
    x=p->data[p->topa];
    p->topa--;
    return x;
}
int pop_b()
{
    int x;
    if (empty_b()) return -1;
    x=p->data[p->topb];
    p->topb--;
    return x;
}
int main()
{
    init();
    int i,j=1,a;
    while(j==1)
    {
        cout<<"\n1-push in stack A\n2-pop from stack A\n3-push in stack B\n4-pop from stack B\n5-any no to exit\n";
        cout<<"enter your choice:-";
        cin>>i;
        switch(i)
        {
            case 1:
            {
                push_a();
                break;
            }
            case 2:
            {
                cout<<"pooped element:- "<<pop_a();
                break;
            }
            case 3:
            {
                push_b();
                break;
            }
            case 4:
            {
                cout<<"pooped element:- "<<pop_b();
                break;
            }
            default:
            {
                j=0;
            }
        }
    }
}
