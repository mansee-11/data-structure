#include <iostream>
#include <math.h>
using namespace std;
struct power
{
    char data;
    power * next;
};
power *topp, *tempp;

struct coeff
{
    char data;
    coeff *next;
};
coeff *topc, *tempc;

void init()
{
    topp = tempp = NULL;
    topc = tempc = NULL;
}

void pushp(char x)
{
    tempp=new power;
    if(tempp==NULL) return;
    tempp->data=x;
    tempp->next=topp;
    topp=tempp;
}

void pushc(char x)
{
    tempc=new coeff;
    if(tempc==NULL) return;
    tempc->data=x;
    tempc->next=topc;
    topc=tempc;
}
void dispp()
{
    cout<<"power stack:-\n";
    tempp=topp;
    while(tempp!=NULL)
    {
        cout<<tempp->data<<"\n";
        tempp=tempp->next;
    }
}
void dispc()
{
    cout<<"coefficent stack:-\n";
    tempc=topc;
    while(tempc!=NULL)
    {
        cout<<tempc->data<<"\n";
        tempc=tempc->next;
    }
}

int main()
{
    string poly;
    cout<<"enter polynomial:- ";
    cin>>poly;
    
    for(int i=0;i<=poly.length()-1;i++)
    {
        if(poly[i] == 'x' && i == 0)
        {
            pushc('1');
            if(poly[i+1] >= 48 && poly[i+1] <= 57)
            {
                pushp(poly[i+1]);
            }
        }
        else if(poly[i] == 'x')
        {
            if(poly[i+1] == '+')
            {
                pushp('1');
            }
            else if(poly[i+1] >= 48 && poly[i+1] <=57)
            {
                pushp(poly[i+1]);
            }
             if (poly[i - 1] >= 48 && poly[i - 1] <= 57)
            {
                pushc(poly[i - 1]);
            }
            else if (poly[i - 1] == '+') 
            {
                pushc('1');
            }
        }
        else if (poly[i] != '+' && poly[i] != 'x' && i > 0 && poly[i] >= 48 && poly[i] <= 57 && i == poly.length() - 1)
        {
            pushc(poly[i]);
            pushp('0');
        } 
        else if(poly[i] == '+')
        {
            continue;
        }
    }
    dispc();
    dispp();
}