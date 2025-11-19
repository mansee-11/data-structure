#include <iostream>
using namespace std;
#define max 10

struct stack{
    int data[max];
    int top;
};
stack s1,*p1;
void init()
{
    p1=&s1;
    p1->top=-1;
}
void push1(int x)
{
    p1->top++;
    p1->data[p1->top]=x;
}
void disp()
{
    cout<<"reversed num = ";
    for(int i=0;i!=p1->top+1;i++)
    {
        cout<<p1->data[i];
    }
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
        push1(a);
        num=num/10;
    }
    disp();
}