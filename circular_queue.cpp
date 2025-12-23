#include<iostream>
using namespace std;
#define max 5
struct cqueue
{
    int data[max];
    int front,rear;
};
cqueue *p,Q1;

void init()
{
    p=&Q1;
    p->front=p->rear=max-1;
}

int full()
{
    int n;
    if(p->rear == max-1)
    {
        n=0;
    }
    else
    {
        n=p->rear+1;
    }
    if(n==p->front)
    {
        return 1;
    }  
    else
    {
        return 0;
    }        
}

int empty()
{
    if(p->front == p->rear)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

void EnQ(int x)
{
    if(full()==1) return;
    if(p->rear==max-1)
    {
        p->rear=0;
    }
    else
    {
        p->rear++;
    }
    p->data[p->rear]=x;
}

int DeQ()
{
    int x;
    if(empty()==1) return -1;
    if(p->front == max-1)
    {
        p->front=0;
    }
    else
    {
        p->front++;
    }
    x=p->data[p->front];
    return x;
}

int main()
{
    init();
    EnQ(10);
    EnQ(20);
    
    cout<<DeQ()<<endl;
    
    EnQ(30);
    EnQ(40);

    cout<<DeQ()<<endl;
    cout<<DeQ()<<endl;

    EnQ(50);
    EnQ(60);
    EnQ(70);
    
    cout<<DeQ()<<endl;
    cout<<DeQ()<<endl;
    cout<<DeQ()<<endl;
    cout<<DeQ()<<endl;
    
    return 0; 
}