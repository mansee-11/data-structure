#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
struct node{
    int data;
    node *prev,*next;
};
node *first,*temp,*ttemp,*p;
void init() 
{
    first = temp = ttemp = NULL;
}
void create_first()
{
    first = new node;
    first -> next = first ->prev =NULL;
    cin>>first->data;
}
void add_node()
{
    temp = first;
    while(temp->next!=NULL)
    {
        temp = temp-> next;
    }
    ttemp = new node;
    ttemp ->next = NULL;
    ttemp->prev=temp;
    temp -> next = ttemp;
    cin>>ttemp->data;
}
void disp()
{
    temp = first;
    while(temp->next!=NULL)
    {
        cout<<temp -> data<<"\n";
        temp=temp->next;
    }
    cout<<temp -> data;
}
void add_after(int x, int y)
{
    temp=first;
    while(temp->data !=x)
    {
        temp=temp->next;
    }
    ttemp=temp-> next;
    p=new node;
    p->data=y;
    p->next=ttemp;
    ttemp->prev=p;
    temp->next=p;
    p->prev=temp;
}
void add_before(int x, int y){
   temp=first;
   while(temp->data !=x)
   {
     ttemp=temp;
     temp=temp->next;
   }
   p=new node;
   p->data=y;
   p->next=temp;
   ttemp->next=p;
   temp->prev=p;
   p->prev=ttemp;
}
void add_before_first(int x){
   temp=new node;
   temp->data=x;
   temp->prev=NULL;
   temp->next=first;
   first->prev=temp;
   first=temp;
}
void add_before_last(int x)
{
    temp=first;
    while(temp->next!=NULL)
    {
        ttemp=temp;
        temp=temp->next;
    }
    p=new node;
    p->data=x;
    p->next=temp;
    temp->prev=p;
    p->prev=ttemp;
    ttemp->next=p;
}
void del_first()
{
    temp=first;
    first->next->prev=NULL;
    temp->next=temp->prev=NULL;
    first=first->next;
    delete temp;
}
void del_after(int x){
  temp=first;
  while(temp->data!=x)
  {
    temp=temp->next;
  }
  ttemp=temp->next;
  p=ttemp->next;
  temp->next=p;
  p->prev=temp;
  ttemp->next=ttemp->prev=NULL;
  delete ttemp;
}
void del_before(int x){     
    temp=first;
    while(temp->data!=x)
    {
        temp=temp->next;
    }
    p=temp->prev;
    ttemp=p->prev;
    ttemp->next=temp;
    temp->prev=ttemp;
    p->next=p->prev=NULL;
    delete p;
}
void del_secondlast()
{
    temp=first;
    while(temp->next!=NULL)
    {
        ttemp=temp;
        temp=temp->next;
    }
    p=ttemp->prev;
    temp->prev=p;
    p->next=temp;
    ttemp->next=ttemp->prev=NULL;
    delete ttemp;
}
void swap12()
{
  temp=first;
  ttemp=temp->next;
  p=ttemp->next;
  ttemp->next=temp;
  temp->prev=ttemp;
  temp->next=p;
  p->prev=temp;
  ttemp->prev=NULL;
  first=ttemp;
}
void swap_1_last(){
  temp=first;
  while(temp->next!=NULL)
  {
    ttemp=temp;
    temp=temp->next;
  }
  p=first->next;
  p->prev=temp;
  ttemp->next = first;
  first->prev=ttemp;
  first->next=NULL;
  temp->next=p;
  temp->prev=NULL;
  first=temp;   
}
void swapmn(int x,int y)
{
    temp=first;
    while(temp->data!=x)
    {
        temp=temp->next;
    }
    ttemp=first;
    while(ttemp->data!=y)
    {
        ttemp=ttemp->next;
    }
    ttemp->prev->next=temp;
    temp->prev->next=ttemp;
    p=temp->prev;
    temp->prev=ttemp->prev;
    ttemp->prev=p;

    temp->next->prev=ttemp;
    ttemp->next->prev=temp;
    p=temp->next;
    temp->next=ttemp->next;
    ttemp->next=p;
}
void reverse()
{
    temp=first;
    p=ttemp=NULL;
    while(temp!=NULL)
    {
        ttemp=temp->next;
        temp->next=p;
        p=temp;
        temp->prev=ttemp;
        temp=ttemp;
    }
    first=p;
}
int main()
{
    int i, a, b, n,j=1;
    init();
    cout<<"enter no of node in link list:-";
    cin>>n;
    cout << "enter element one by one to create link list:-\n";
    create_first();
    for (i = 0; i < n-1; i++)
    {
        add_node();
    }
    while (j==1)
    {
        cout << "\n1- add node after given data\n2-add before 1st node \n3-add before given data";
        cout << "\n4-add before last node\n5-del before given data\n6-del after given data\n";
        cout << "7-delfirst node\n8-del secondlast node\n9-swap 1st and 2nd\n10-swap 1st and last";
        cout << "\n11-swap mth and nth term\n12-display\n13-reverse\n14-exit\n";
        cout << "enter your choice from the menu:-";
        cin >> i;
        switch (i)
        {
        case 1:
        {
            cout << "input data to add after it and theen enter data to be added";
            cin >> a >> b;
            add_after(a, b);
            break;
        }
        case 2:
        {
            cout << "enter data to add ";
            cin >> a;
            add_before_first(a);
            break;
        }
        case 3:
        {
            cout << "enter data to add before then enter data to add";
            cin >> a >> b;
            add_before(a, b);
            break;
        }
        case 4:
        {
            cout << "enter element to add";
            add_before_last(a);
            break;
        }
        case 5:
        {
            cout << "enter data to del before it ";
            cin >> a;
            del_before(a);
            break;
        }
        case 6:
        {
            cout << "enter data to del after it";
            cin >> a;
            del_after(a);
            break;
        }
        case 7:
        {
            del_first();
            break;
        }
        case 8:
        {
            del_secondlast();
            break;
        }
        case 9:
        {
            swap12();
            break;
        }
        case 10:
        {
            swap_1_last();
            break;
        }
        case 11:
        {
            cout << "enter both data to exchange position";
            cin >> a >> b;
            swapmn(a, b);
            break;
        }
        case 12:
        {
            disp();
            break;
        }
        case 13:
        {
            reverse();
        }
        default:
        {
            j = 0;
        }
        }
    }
}
