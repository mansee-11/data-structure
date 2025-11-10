#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *first, *temp, *ttemp, *p;
void init()
{
    first = temp = ttemp = NULL;
}
void create_first()
{
    first = new node;
    first->next = NULL;
    cin >> first->data;
}
void add_node()
{
    temp = first;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    ttemp = new node;
    ttemp->next = NULL;
    temp->next = ttemp;
    cin >> ttemp->data;
}

void disp()
{
    temp = first;
    while (temp->next!= NULL)
    {
        cout << temp->data << "\n";
        temp = temp->next;
    }
    cout << temp->data << "\n";
}
void del_first()
{
    temp = first;
    first = first->next;
    temp->next = NULL;
    delete temp;
}
void del_after(int x)
{
    temp = first;
    while (temp->data != x)
    {
        temp = temp->next;     
    }
    ttemp = temp->next;
    p = ttemp->next;
    temp->next = p;
    ttemp->next = NULL;
    delete ttemp;
}

void del_before(int x)
{

    temp = first;
    while (temp->next->data != x)
    {
        ttemp = temp;
        temp = temp->next;
    }
    p = temp->next;
    ttemp->next = p;
    temp->next = NULL;
    delete temp;

}
void del_secondlast()
{
    temp = first;
    while (temp->next->next != NULL)
    {
        ttemp = temp;
        temp = temp->next;
    }
    p = temp->next;
    temp->next = NULL;
    ttemp->next = p;
    delete temp;
}
void swap12()
{
    temp = first;
    ttemp = temp->next;
    p = ttemp->next;
    ttemp->next = temp;
    temp->next = p;
    first = ttemp;
}
void swap_1_last()
{
    temp = first;
    while (temp->next != NULL)
    {
        ttemp = temp;
        temp = temp->next;
    }
    p = first->next;
    ttemp->next = first;
    first->next = NULL;
    temp->next = p;
    first = temp;
}
void add_after(int x, int y)
{
    temp = first;
    while (temp->data != x)
    {
        temp = temp->next;
    }
    ttemp = temp->next;
    p = new node;
    p->data = y;
    p->next = temp;
    temp->next = p;
}

void add_before(int x, int y)
{
    temp = first;
    while (temp->data != x)
    {
        ttemp = temp;
        temp = temp->next;
    }
    p = new node;
    p->data = y;
    p->next = temp;
    ttemp->next;
}

void add_before_first(int x)
{
    temp = new node;
    temp->data = x;
    temp->next = first;
    first = temp;
}

void add_before_last(int x)
{
    temp = first;
    while (temp->next != NULL)
    {
        ttemp = temp;
        temp = temp->next;
    }
    p = new node;
    p->data = x;
    p->next = temp;
    ttemp->next = p;
}
void swapmn(int x, int y)
{
    temp = first;
    while (temp->next->data != x)
    {
        temp = temp->next;
    }
    ttemp = first;
    while (ttemp->next->data != y)
    {
        ttemp = ttemp->next;
    }
    p = temp->next;
    temp->next = ttemp->next;
    ttemp->next = p;
    p = temp->next->next;
    temp->next->next = ttemp->next->next;
    ttemp->next->next = p;
}
void reverse()
{
    temp=first;
    p=NULL;
    ttemp=NULL;
    while(temp!=NULL)
    {
        ttemp=temp->next;   //saving next value in ttemp
        temp->next=p;       //changing next value
        p=temp;             //saving prev value in p
        temp=ttemp;         //going on next
    }
    first=p;
}
struct node1
{
    int data1;
    node1 *next1;
};
node1 *first1,*temp1,*ttemp1,*p1;
void init1()
{
    first1=temp1=ttemp1=p1=NULL;
}
void create_first1()
{
    first1 = new node1;
    first1->next1= NULL;
    first1->data1=first->data;
}
void create_ll2()
{
    init1();
    create_first1();
    temp=first;
    temp1=first1;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        ttemp1=new node1;
        temp1->next1=ttemp1;
        temp1=ttemp1;
        ttemp1->data1=temp->data;
        ttemp1->next1=NULL;
    }
}    
void reverse_ll2()
{    
    create_ll2();
    temp1=first1;
    ttemp1=NULL;
    p1=NULL;
    while(temp1!=NULL)
    {
        ttemp1=temp1->next1;
        temp1->next1=p1;
        p1=temp1;
        temp1=ttemp1;
    }
    first1=p1;
}
void palindrome()
{
    reverse_ll2();
    temp=first;
    temp1=first1;
    while(temp!=NULL)
    {
        if(temp->data!=temp1->data1)
        {
            cout<<"not palindrome"<<"\n";
            break;
        }
        temp=temp->next;
        temp1=temp1->next1;
    }
    if(temp==NULL)
    {
        cout<<"palindrome"<<"\n";
    }
}
void disp1()
{
    temp1 = first1;
    while (temp1->next1!= NULL)
    {
        cout << temp1->data1 << "\n";
        temp1 = temp1->next1;
    }
    cout << temp1->data1 << "\n";
}
struct llo
{
    int datao;
    llo *nexto;
};
llo *tempo,*ttempo,*po,*firsto;
struct lle
{
    int datae;
    lle *nexte;
};
lle *tempe,*ttempe,*pe,*firste;
void inito()
{
    firsto=tempo=ttempo=NULL;
}
void create_firsto()
{
    inito();
    firsto = new llo;
    firsto->nexto= NULL;
    firsto->datao=temp->data;
}
void inite()
{
    firste=tempe=ttempe=NULL;
}
void create_firste()
{
    inite();
    firste = new lle;
    firste->nexte= NULL;
    firste->datae=temp->data;
}
void odd_even()
{
    temp=first;
    int o=0,e=0;
    tempo=ttempo=NULL;
    tempe=ttempe=NULL;
    while(temp!=NULL)
    {
        if((temp->data)%2==0)
        {
            if(e==0)
            {
                create_firste();
                ttempe=firste;
                e+=1;
            }
            else
            {
                tempe=new lle;
                tempe->datae=temp->data;
                tempe->nexte=NULL;
                ttempe->nexte=tempe; 
                ttempe=tempe;
            }
            temp=temp->next;
        }
        else
        {
            if(o==0)
            {
               create_firsto();
               ttempo=firsto;
               o+=1;
            }
            else
            {
                tempo=new llo;
                tempo->datao=temp->data;
                tempo->nexto=NULL;
                ttempo->nexto=tempo;
                ttempo=tempo;
            }
            temp=temp->next;
        }
    }
}
void dispo()
{
    cout<<"odd elements \n";
    tempo = firsto;
    while (tempo->nexto!= NULL)
    {
        cout << tempo->datao << "\n";
        tempo = tempo->nexto;
    }
    cout << tempo->datao << "\n";
}
void dispe()
{
    cout<<"even elements \n";
    tempe = firste;
    while (tempe->nexte!=NULL)
    {
        cout << tempe->datae << "\n";
        tempe = tempe->nexte;
    }
    cout << tempe->datae << "\n";
}
int main()
{
    int i, a, b, n, j=1;
    init();
    cout <<"enter no. of element you want in link list:= ";
    cin >> n;
    cout << "enter element one by one to create link list:-\n";
    create_first();
    for (i = 0; i < n-1; i++)
    {
        add_node();
    }
    while (j==1)
    {
        cout << "1- add node after given data\n2-add before 1st node \n3-add before given data\n4-add before last node";
        cout << "5-del before given data\n6-del after given data\n7-delfirst node\n8-del secondlast node ";
        cout << "9-swap 1st and 2nd\n10-swap 1st and last\n11-swap mth and nth term\n";
        cout<<"12-display\n13-reverse link list\n14-palindrome\n15-create to link list odd and even\n16-exit\n";
        cout << "enter your choice from the menu:-";
        cin >> i;
        switch (i)
        {
        case 1:
        {
            cout << "input data to add after it and then enter data to be added";
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
            break;
        }
        case 14:
        {
            palindrome();
        }
        case 15:
        {
            odd_even();
            dispo();
            dispe();
            break;
        }
        default:
        {
            j = 0;
        }
        }
    }
}