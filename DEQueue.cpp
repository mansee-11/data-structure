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
        for(int i=p->rear;i>=p->front;i--)
        {
            p->data[i+1]=p->data[i];
        }
        p->data[p->front]=x;
        ++p->rear;
    }
}
void EEnQ(int x)
{
    if(full()==1) return;
    if(p->rear==-1)
    {
        p->front=p->rear=0;
        p->data[p->rear]=x;
    }
    else if(p->rear!=max-1)
    {
        p->rear++;
        p->data[p->rear]=x;
    }
    else
    {
        for(int i=p->front;i<=p->rear;i++)
        {
            p->data[i-1]=p->data[i];
        }
        --p->front;
        p->data[p->rear]=x;
    }
}

int BDeQ()
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
int EDeQ()
{
    int x;
    if(empty()==1) return -1;
    x=p->data[p->rear];
    if(p->front==p->rear)
    {
        p->front=p->rear=-1;
    }
    else
    {
        p->rear--;
    }
    return x;
}

int main()
{
    init();
    BEnQ(10);
    BEnQ(20);
    BEnQ(30);
    EEnQ(40);
    EEnQ(50);
    EEnQ(60); //full can't be inserted
    cout<<BDeQ()<<endl;
    cout<<BDeQ()<<endl;
    cout<<EDeQ()<<endl;
    cout<<EDeQ()<<endl;
}