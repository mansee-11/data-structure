#include<iostream>
using namespace std;
struct stack{
    string data;
    int top;
};
stack *p1,*p2,s1,s2;
void init()
{
    p1=&s1;
    p2=&s2;
    p1->top=-1;
    p2->top=-1;
}
void push1(int a)
{
    p1->top++;
    p1->data+=a;
}
void push2(int a)
{
    p2->top++;
    p2->data+=p1->data[a];
}
int main()
{
    init();
    string s;
    cout<<"enter a string to check palindrome:-";
    cin>>s;
    int x=s.length();
    for(int i=0;i<x;i++)
    {
        push1(s[i]);
    }
    for(int i=x-1,j=0;i>=0;i--,j++)
    {
        push2(i);
    }
    if(p1->data==p2->data)
    {
        cout<<"palindrome";
    }
    else
    {
        cout<<"not palindrome";
    }
}