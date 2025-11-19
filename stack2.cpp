#include <iostream>
using namespace std;

struct stack{
    int data;
    stack *next;
};
stack *temp,*top;
void init()
{
    temp=top=NULL;
}
void push(int x)
{
    temp=new stack;
    temp->data=x;
    temp->next=top;
    top=temp;    
}
void disp()
{
    cout<<"reversed num = ";
    temp=top;
    do{
        cout<<temp->data;
        temp=temp->next;
    }while(temp!=NULL);
}
int main()
{
    init();
    int num,a;
    cout<<"enter a number to reverse = ";
    cin>>num;
    while(num!=0)
    {
        a=num%10;
        push(a);
        num=num/10;
    }
    disp();
    return 0;
}