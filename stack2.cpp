#include <iostream>
using namespace std;

struct stack{
    int data;
    stack *next;
};
stack *temp,*top,*top1;
void init()         //to initialise stack
{
    temp=top=NULL;
}
void push(int x)    //to push digit in stack
{
    temp=new stack;     //to add new node
    temp->data=x;       
    temp->next=top;     //to link it to linked list
    top=temp;           //increasing top
}
int pop()           //do like del first
{
    int x;
    if(top==NULL)return -1;     //to check if stack is empty
    temp=top;                   
    x=temp->data;               //taking data of top node
    top=top->next;              //shifting top back(decreasing)
    temp->next=NULL;
    delete temp;                //deleting top node
    return x;
}
void push1(int x)        //to push data in stack2
{
    temp=new stack;     //to add new node
    temp->data=x;       
    temp->next=top1;     //to link it to linked list
    top1=temp;           //increasing top
}
int pop1()
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
    int num,a,b;
    cout<<"enter a number to reverse = ";
    cin>>num;
    while(num!=0)       //to push each digit of number in stack
    {
        a=num%10;       //to get a digit from num
        push(a);        //push that digit in stack
        num=num/10; 
    }
    while(top!=NULL)    //to push each digit in stack 2 
    {
       push1(pop());
    }
    while(top1!=NULL)    //to pop each digit from stack 2
    {
       b*=10;
       b+=pop1();
    }
    cout<<"reversed num = "<<b;
    return 0;
}