#include<iostream>
using namespace std;

struct queue
{
    int data;
    queue *next;
};

queue *front,*rear,*temp,*ttemp;

void init()
{
    front=rear=temp=ttemp=NULL;
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

void BEnQ(int x)
{
    temp=new queue;

    if(temp==NULL) return;

    if(front==NULL)
    {
        temp->next=NULL;
        rear=front=temp;
    }
    else
    {
        temp->next=front;
        front=temp;
    }
    temp->data=x;
}

int BDeQ()
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
void EEnQ(int x)
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

int EDeQ()
{
    int x;
    if(empty()==1) return -1;
    x=rear->data;
    if(front==rear)
    {
        temp=rear;
        temp->next=NULL;
        front=rear=NULL;
        delete temp;
    }
    else
    {
        temp=front;
        while (temp->next!= rear)
        {
            temp = temp->next;
        }
        temp->next=NULL;
        ttemp=rear;
        rear=temp;
        delete ttemp;
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

    cout<<BDeQ()<<endl;
    cout<<BDeQ()<<endl;
    cout<<EDeQ()<<endl;
    cout<<EDeQ()<<endl;
    cout<<EDeQ()<<endl;
}