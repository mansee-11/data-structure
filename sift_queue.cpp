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
    if(p->rear==max-1)
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

void EnQ(int x)
{
    if(full()==1) return;
    if(p->rear==-1)
    {
        p->front=p->rear=0;
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
    x=p->data[p->front];
    if(p->front==p->rear)
    {
        p->front=p->rear=-1;
    }
    else
    {
        p->data[p->front]=p->data[p->front+1];
        for(int i=p->front+1;i<p->rear;i++)
        {
            p->data[i]=p->data[i+1];
        }
        p->rear--;
    }
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
    EnQ(80);
    
    cout<<DeQ()<<endl;
    cout<<DeQ()<<endl;
    cout<<DeQ()<<endl;
    cout<<DeQ()<<endl;
    cout<<DeQ()<<endl;
}