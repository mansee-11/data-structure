#include<iostream>
using namespace std;
#define max 5

struct queue
{
    int data[max];
    int front,rear;
};

queue *p,q1;

void init()
{
    p=&q1;
    p->front=p->rear=-1;
}

int full()
{
    if(p->front==0 && p->rear==max-1)
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
    if(p->front==-1)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

void BEnQ(int x)
{
    if(full()==1) return;
    if(p->front==-1)
    {
        p->front=p->rear=0;
        p->data[p->front]=x;
    }
    else if(p->front!=0)
    {
        --p->front;
        p->data[p->front]=x;
    }
    else
    {
        for
    }
}

int DeQ()
{
    int x;
    if(empty()==1) return -1;
    x=p->data[p->front];
    if(p->front==p->rear)
    {
        p->front=p->rear=-1;
    }
    else
    {
        p->front++;
    }
    return x;
}

int main()
{
    init();
    EnQ(10);
    EnQ(20);
    EnQ(30);
    EnQ(40);
    EnQ(50);
    EnQ(60); //full can't be inserted
    cout<<DeQ()<<endl;
    cout<<DeQ()<<endl;
    cout<<DeQ()<<endl;
