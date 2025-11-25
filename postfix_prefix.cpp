#include <iostream>
using namespace std;
struct stack
{
    string data;
    stack *next;
};
stack *top, *temp;
void init()
{
    top = temp = NULL;
}
void push(string x)
{
    temp = new stack;
    temp->next = top;
    top = temp;
    temp->data = x;
}
string pop()
{
    string x;
    if (top == NULL)
        return "#";
    temp = top;
    x = temp->data;
    top = top->next;
    temp->next = NULL;
    delete temp;
    return x;
}
int main()
{
    int i;
    string postfix, s1, s2, s3, s4, s5;
    init();
    cout << "enter postfix:- ";
    cin >>postfix;
    for (i = 0; i <postfix.length(); i++)
    {
        if (isalnum(postfix[i]))
        {
            string ch;
            ch+=postfix[i];
            push(ch);
        }
        else
        {
            s1 = pop();
            s2 = pop();
            s3 =postfix[i];
            s4 = s3 + s2;
            s5 = s4 + s1;
            push(s5);

        }
    }
    while (top->next!= NULL)
    {
        s1 = pop();
        s2 = pop();
        s3= s1 + s2;
        push(s3);
    }
    cout<<"prefix = "<<top->data;
}