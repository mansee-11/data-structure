#include<iostream>
using namespace std;
void hanoi(int n,char from,char to ,char aux)
{
    if(n==1)
    {
        cout<<"move disk 1 from "<<from<<" to "<<to<<endl;
        return;
    }
    hanoi(n-1,from,aux,to);
    cout<<"move disk "<<n<<" from "<<from<<" to "<<to<<endl;
    hanoi(n-1,aux,to,from);
}
int main()
{
    hanoi(5,'A','c','b');
}