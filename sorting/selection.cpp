#include<iostream>
using namespace std;

void selection_s(int arr[],int n)
{
    for(int i=n-1;i>=0;i--)
    {
        int large=arr[0];
        int j,index=0;
        for(j=1;j<=i;j++)
        {
            if(arr[j]>large)
            {
                large=arr[j];
                index=j;
            }
        }
        arr[index]=arr[i];
        arr[i]=large;
    }
}
int main()
{
    int a[50];
    int n;

    cout << "enter no. of element in array:-";
    cin >> n;

    cout << "enter element of array one by one:-";
    for (int i=0; i<n; i++)
    {
        cin >>a[i];
    }

    selection_s(a,n);
    cout<<"sorted array:- ";
    for (int i=0; i<n; i++)
    {
        cout <<a[i]<<" ";
    }
}