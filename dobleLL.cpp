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
    first -> next = NULL;
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
    temp -> next = ttemp;
    cin>>ttemp->data;
}
void del_first()
{
    temp=first;
    first=first->next;
    temp ->next=NULL;
    delete temp;
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
void del_after(int x){
  temp=first;
  while(temp->data!=x)
  {
    temp=temp->next;
  }
  ttemp=temp->next;
  p=ttemp->next;
  temp->next=p;
  ttemp->next=NULL;
  delete ttemp;
}

void del_before(int x){
      
    temp=first;
    while(temp->next->data!=x){
        ttemp=temp;
        temp=temp->next;
    }
    p=temp->next;
    ttemp->next=p;
    temp->next=NULL;
    delete temp;
 }
 void del_secondlast()
 {
  temp=first;
  while(temp->next->next!=NULL){
          ttemp=temp;
          temp=temp->next;
      }
      p=temp->next;
      temp->next=NULL;
      ttemp->next=p;
      delete temp;
}
void swap12(){
  temp=first;
  ttemp=temp->next;
  p=ttemp->next;
  ttemp->next=temp;
  temp->next=p;
  first=ttemp;
}
void swap_1_last(){
  temp=first;
  while(temp->next!=NULL){
    ttemp=temp;
    temp=temp->next;
  }
  p=first->next;
  ttemp->next = first;
  first->next=NULL;
  temp->next=p;
  first=temp;   
}
void add_after(int x, int y){
    temp=first;
    while(temp ->data !=x){
            temp=temp->next;
    }
    ttemp=temp-> next;
    p=new node;
    p->data=y;
    p->next=temp;
    temp->next=p;
}

void add_before(int x, int y){
   temp=first;
   while(temp->data !=x){
     ttemp=temp;
     temp=temp->next;
   }
   p=new node;
   p->data=y;
   p->next=temp;
   ttemp->next;
}

void add_before_first(int x){
   temp=new node;
   temp->data=x;
   temp->next=first;
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
    ttemp->next=p;
}

int main()
{
    init();
    create_first();
    add_node();
    add_node();
    add_node();
    add_before(5,7);
    del_after(5);
    del_before(2);
    del_secondlast();
    swap_1_last();
    swap12();
    disp();
}
