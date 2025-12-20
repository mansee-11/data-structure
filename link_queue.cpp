#include<iostream>
using namespace std;

struct queue
{
    int data;
    queue *next;
};

queue *front,*rear,*temp;

void init()
{
    front=rear=temp=NULL;
}

int empty()
{
    if(front==NULL)
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
    temp=new queue;

    if(temp==NULL) return;

    if(rear==NULL)
    {
        rear=front=temp;
    }
    else
    {
        rear->next=temp;
        rear=temp;
    }
    temp->data=x;
    temp->next=NULL;
}

int DeQ()
{
    int x;
    if(empty()==1) return -1;
    x=front->data;
    temp=front;
    if(front==rear)
    {
        front=rear=NULL;
    }
    else
    {
        front=front->next;
    }
    
    temp->next=NULL;
    delete temp;
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

    cout<<DeQ()<<endl;
    cout<<DeQ()<<endl;
    cout<<DeQ()<<endl;
    cout<<DeQ()<<endl;
    cout<<DeQ()<<endl;
    cout<<DeQ()<<endl;
}