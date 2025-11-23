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
string rev(string x)
{
    char ch;
    for(int i=0,j=x.length()-1;i<j;i++,j--)
    {
        ch=x[i];
        x[i]=x[j];
        x[j]=ch;
    }
    return x;
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
    string prefix, s1, s2, s3, s4, s5;
    init();
    cout << "enter prefix:- ";
    cin >> prefix;
    prefix=rev(prefix);
    for (i = 0; i < prefix.length(); i++)
    {
        if (isalnum(prefix[i]))
        {
            string ch;
            ch+=prefix[i];
            push(ch);
        }
        else
        {
            s1 = pop();
            s2 = pop();
            s3 = prefix[i];
            s4 = s1 + s3;
            s5 = s4 + s2;
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
    cout<<"infix = "<<top->data;
}