#include <iostream>
using namespace std;
struct stack
{
    char data;
    stack *next;
};
stack *top1, *temp;
struct stack2
{
    string data;
    stack2 *next;
};
stack2 *top2,*temp2;
void init()
{
    top1 = temp = NULL;
    top2 = temp2 = NULL;
}
void push1(char x)
{
    temp = new stack;
    temp->next = top1;
    top1 = temp;
    temp->data = x;
}
void push2(string x)
{
    temp2 = new stack2;
    temp2 -> next = top2;
    top2 = temp2;
    temp2->data = x;
}
char pop1()
{
    char x;
    if (top1 == NULL)
        return '#';
    temp = top1;
    x = temp->data;
    top1 = top1->next;
    temp->next = NULL;
    delete temp;
    return x;
}
string pop2()
{
    string x;
    if (top2 == NULL) return "#";
    temp2 = top2;
    x = temp2->data;
    top2 = top2->next;
    temp2->next = NULL;
    delete temp2;
    return x;
}
int priority(char x)
{
    if (x == '^')
        return 3;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '+' || x == '-')
        return 1;
    return 0;
}
int main()
{
    int i;
    string infix, s1, s2, s3, s4, s5;
    init();
    cout << "enter infix:- ";
    cin >> infix;
    for (i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
        {
            push1(infix[i]);
        }
        else if (isalnum(infix[i]))
        {
            string ch="";
            ch+=infix[i];
            push2(ch);
        }
        else if (infix[i] == ')')
        {
            while (top1 != NULL && top1->data != '(')
            {
                s1 = pop2();
                s2 = pop2();
                s3 = pop1();
                s4 = s2 + s1;
                s5 = s3 + s4;
                push2(s5);
            }
            pop1();
        }
        else
        {
            if (top1 != NULL && top1->data == '(')
                push1(infix[i]);
            else
            {
                while (top1 != NULL && priority(top1->data) >= priority(infix[i]))
                {
                    s1 = pop2();
                    s2 = pop2();
                    s3 = pop1();
                    s4 = s2 + s1;
                    s5 = s3 + s4;
                    push2(s5);
                }
                push1(infix[i]);
            }
        }
    }
    while (top1 != NULL)
    {
        s1 = pop2();
        s2 = pop2();
        s3 = pop1();
        s4 = s2 + s1;
        s5 = s3 + s4;
        push2(s5);
    }
    while(top2->next!=NULL)
    {
        s1=pop2();
        s2=pop2();
        push2(s1+s2);
    }
    cout<<"prefix = "<<top2->data;
}