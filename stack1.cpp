#include<iostream>
using namespace std;
struct stack{
    string data;
    int top;
};
stack *p1,*p2,s1,s2;
void init()     //to initialise both stacks
{
    p1=&s1;
    p2=&s2;
    p1->top=-1;
    p2->top=-1;
}
void push1(char a)       //to push data in stack 1
{
    p1->top++;          //increase value of top
    p1->data+=a;        //adding char to the string in stack
}
void push2(int a)       //to push reversed string in stack 2
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
    for(int i=0;i<x;i++)    //to push each char of string in stack as a element
    {
        push1(s[i]);
    }
    for(int i=x-1;i>=0;i--) //to push each element of first stack in second stack reversly
    {
        push2(i);
    }
    if(p1->data==p2->data)  //to check palindrome
    {
        cout<<"palindrome";
    }
    else
    {
        cout<<"not palindrome";
    }
}