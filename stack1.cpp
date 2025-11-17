#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;
#define max 50

struct stack{
    char data[max];
    int top;
};
stack s1,*p1,s2,*p2; 

void init()         //to initialise both stacks
{
    p1=&s1;
    p2=&s2; 
    p1->top=-1;
    p2->top=-1;
}

void push2()    //to input data of stack 1 in stack 2 using lifo
{
    int x=p1->top-1;   //p1->top will have '\0' so taking 1 less from top
    int i=0;
    for(x,i;x>-1;x--,i++)   //x is decresing from top-1 to -1 and i is increasing by 1 from 0
    {
        p2->top++;          //shifting top of 2nd stack
        p2->data[i]=p1->data[x];   //pusing data in stack 2 reverse of stack 1
    }
}
void palindrome()       // to check palindrome
{
    int i;
    for(i=0;i<p1->top;i++)
    {
        if((p1->data[i])!=(p2->data[i]))    //checking if same index having same char or not on reversing
        {                                   
            cout<<"not palindrome";         //if not same then print not palindrome
            break;
        }
    }
    if(p1->data[i]=='\0')   //to check if i reached end that means all char in stack1 and stack2 are same
    {       
        cout<<"palindrome";     
    }
}
int main()
{
    init();
    cout<<"enter a string to check palindrome:- ";
    cin>>p1->data;      //diectly giving stack 1 data (string)
    int i=0;
    while(p1->data[i]!='\0')    //to get length of the string
    {
        i++;
    }
    p1->top=i;  //giving top of stack 1 its value (length of string)
    push2(); 
    palindrome();
}