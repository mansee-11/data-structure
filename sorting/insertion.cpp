#include<iostream>
using namespace std;

void insertion_s(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        if(arr[i]<arr[i-1])
        {
            int j=i,temp=arr[i];
            do
            {
                arr[j]=arr[j-1];
                j--;
            }while(j>0 && arr[j-1]>temp);
            arr[j]=temp;
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

    insertion_s(a,n);
    cout<<"sorted array:- ";
    for (int i=0; i<n; i++)
    {
        cout <<a[i]<<" ";
    }
}