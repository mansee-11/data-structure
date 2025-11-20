#include<iostream>
using namespace std;
struct stack{
    char data;
    stack *next;
};
stack *temp,*top,*top1,*top2;
void init()     //initialising the stack
{
    temp=top=top1=top2=NULL;
}
void push(char x)   //pushing data in main stack(alphanumeric)
{
    // same as add before first in simple linked list

    temp=new stack;     //creating new node       
    temp->next=top;     // temp next pointing top(linking)
    top=temp;           // increasing top's value 
    temp->data=x;
}
int pop()
{
    char x;
    if(top==NULL)return -1; //checking if stack is empty
    temp=top;               //temp pointing top
    x=temp->data;           //x having the data in temp
    top=top->next;          //decreasing top to data next to it
    temp->next=NULL;        //removing it from linked list
    delete temp;            //deleting node
    return x;               //return data
}
void push1(int x)       //push function of stack having only alphabets
{
    temp=new stack;
    temp->data=x;
    temp->next=top1;
    top1=temp;
}
void push2(int x)       //push function of stack having only numbers
{
    temp=new stack;
    temp->data=x;
    temp->next=top2;
    top2=temp;
}
void disp1()    //display function of stack having alphabets
{
    cout<<"elements of alphabet stack:-"<<"\n";
    temp=top1;
    do
    {
        cout<<temp->data<<"\n";
        temp=temp->next;
    }while(temp!=NULL);
}
void disp2()    //display function of stack having numbers
{
    cout<<"elements of numaric stack:-"<<"\n";
    temp=top2;
    do
    {
        cout<<temp->data<<"\n";
        temp=temp->next;
    }while(temp!=NULL);
}
int main()
{
    init();
    string s;
    char ch;
    cout<<"enter a alphanumeric data:-";    //taking input from user
    cin>>s;
    int x=s.length();   //to find length of string
    for(int i=0;i<x;i++)
    {
        push(s[i]);     //to push each char/int in main stack
    }
    for(int i=0;i<x;i++)    //to seperate alphabets and numbers
    {
        ch=pop();           //saving poped element in ch variable
        if(ch>='a' && ch<='z')  //checking if pooped element is between a-z 
        {                       
            push1(ch);          //if yes then push it in alphabet stack else goto else if
        }
        else if(ch>='A'&& ch<='Z')  //checking if pooped element between A-Z 
        {
            push1(ch);              //if yes then push it to alphabet stack else goto else
        }
        else                   //when not alphabet then number
        {
            push2(ch);               //push it to number stack
        }
    }
    disp1();       //display alphabet stack data
    disp2();       //display numeric stack data
}