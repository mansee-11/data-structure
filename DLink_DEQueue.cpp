#include<iostream>
using namespace std;

struct dequeue
{
    int data;
    dequeue *prev,*next;
};

dequeue *front,*rear,*temp;

void init()
{
    front=rear=temp=NULL;
}

int isempty()
{
    if(front==NULL) return 1;
    else return 0;
}

void BEnQ(int x)
{
    temp=new dequeue;
    if(temp==NULL) return;

    temp->prev=NULL;

    if(front==NULL)
    {
        front=rear=temp;
        temp->next=NULL;
    }
    else
    {
        temp->next=front;
        front->prev=temp;
        front=temp;
    }
    temp->data=x;
}

void EEnQ(int x)
{
    temp=new dequeue;
    if(temp==NULL) return;
    temp->next=NULL;

    if(rear==NULL)
    {
        front=rear=temp;
        temp->prev=NULL;
    }
    else
    {
        temp->prev=rear;
        rear->next=temp;
        rear=temp;
    }
    temp->data=x;
}

int BDeQ()
{
    if(isempty()==1) return -1;

    int x;
    x=front->data;
    temp=front;

    if(front==rear)
    {
        front=rear=NULL;
    }
    else
    {
        front=temp->next;
        front->prev=NULL;
    }

    temp->next=temp->prev=NULL;
    delete temp;
    return x;
}

int EDeQ()
{
    if(isempty()==1) return -1;

    int x;
    x=rear->data;
    temp=rear;

    if(front == rear)
    {
        front=rear=NULL;
    }
    else
    {
        rear=rear->prev;
        rear->next=NULL;
    }

    temp->prev=temp->next=NULL;
    delete temp;
    return x;
}

int main()
{
    init();

    BEnQ(10);
    EEnQ(40);
    BEnQ(20);
    EEnQ(50);
    BEnQ(30);

    cout<<BDeQ()<<endl;
    cout<<EDeQ()<<endl;
    cout<<EDeQ()<<endl;
    cout<<EDeQ()<<endl;
    cout<<BDeQ()<<endl;
}