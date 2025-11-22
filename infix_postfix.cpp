#include<iostream>
using namespace std;
struct stack{
    char data;
    stack *next;
};
stack *top,*temp;
void init()
{
    top=temp=NULL;
}
void push(char x)
{
    temp=new stack;           
    temp->next=top;
    top=temp;          
    temp->data=x;
}
char pop()
{
    char x;
    if(top==NULL)return '#'; 
    temp=top;
    x=temp->data;           
    top=top->next;           
    temp->next=NULL;        
    delete temp;            
    return x; 
}
int priority(char x)
{
    if(x=='^') return 3;
    else if(x =='*' || x=='/') return 2;
    else if(x =='+' || x=='-') return 1;
    return 0;
}
int main()
{
    int i;
    string infix,post;
    init();
    cout<<"enter infix:- ";
    cin>>infix;
    for(i=0 ;i<infix.length();i++)
    {
        if(infix[i]=='(') push(infix[i]);
        else if(isalnum(infix[i])) post+=infix[i];
        else if (infix[i]==')')
        {
            while(top!=NULL && top->data!='(') post+=pop();
            pop();
        }
        else
        {
            if(top!=NULL && top->data=='(') push(infix[i]);
            else
            {
                while(top!=NULL && priority(top->data)>=priority(infix[i])) post+=pop();
                push(infix[i]);
            }
        }
    }
    while(top!=NULL) post+=pop();
    cout<<"postfix of given in fix ="<<post;
}