#include<iostream>
using namespace std;

void bubble_s(int arr[],int n)
{
    int check=1;
    for(int i=0;i<n && check==1;i++)
    {
        check=0;
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                check=1;
                arr[j] = arr[j] + arr[j+1];
                arr[j+1] = arr[j] - arr[j+1];
                arr[j] = arr[j] - arr[j+1];
            }
        }
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

    bubble_s(a,n);
    cout<<"sorted array:- ";
    for (int i=0; i<n; i++)
    {
        cout <<a[i]<<"\n";
    }
}