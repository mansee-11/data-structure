#include<iostream>
using namespace std;
int count=0;
void hanoi(int n,char from,char to ,char aux)
{
    if(n==1)
    {
        count++;
        cout<<count<<"- move disk 1 from "<<from<<" to "<<to<<endl;
        return;
    }
    hanoi(n-1,from,aux,to);
    count++;
    cout<<count<<"- move disk "<<n<<" from "<<from<<" to "<<to<<endl;
    hanoi(n-1,aux,to,from);
}
int main()
{
    int no;
    cout<<"enter no. of disk(less then 10) = ";
    cin>>no;
    hanoi(no,'A','c','b');
}