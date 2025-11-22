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
void push(int x)        //to push in main function
{
    temp=new stack;     //create new node       
    temp->next=top;     //linking it to linked list
    top=temp;           //increasing top (shifting)
    top->data=x;        //pushing data 
}
void push1()   //to push in 1st stack
{
    int x;
    cin>>x;
    temp=new stack;
    temp->data=x;
    temp->next=top1;
    top1=temp;
}
void push2()    //to push in second stack
{
    int x;
    cin>>x;
    temp=new stack;
    temp->data=x;
    temp->next=top2;
    top2=temp;
}
int pop1()     //to pop element from stack 1
{
    int x;
    if(top1==NULL)return -1;    //check if stack is empty
    temp=top1;              
    x=temp->data;           //taking the data of top node of stack
    top1=top1->next;        //shifting back top(decreaing its position)
    temp->next=NULL;        //removing it from linked list 
    delete temp;            //deleting top node
    return x;               //return data
}
int pop2()      //to pop element of second stack
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
void disp()     //to display the elements of merged stack
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
    cout<<"enter data for stack 1:-"<<"\n";     //to push data in stack 1
    for(i=0;i<n;i++)
    {
        push1();
    }
    cout<<"enter data for stack 2:-"<<"\n";     //to push data in stack 2
    for(i=0;i<n;i++)
    {
        push2();
    }
    for(i=0;i<n;i++)    //pushing data in merged stack one by one from both stacks
    {
        push(pop1());   //to push data in merged stack poped from 1st stack
        push(pop2());   //to push data in merged stack poped from 2nd stack
    }
    disp(); //to display elements of merged stack
}