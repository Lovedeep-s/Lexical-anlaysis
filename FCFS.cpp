//This code is made by Lovedeep singh
#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
cout<<"Enter the number of process = ";
cin>>n;
int *arr,*arr2 ,*arr3,*wait;
arr = new int[n];
arr2 = new int[n];
arr3 = new int[n];
wait = new int[n];
for (int i = 0; i < n; i++)
{
    arr[i]=i+1;
    cout<<"input the arrival time of process "<<i+1<<" = ";
    cin>>arr2[i];
    cout<<"input the CPU time of process "<<i+1<<" = ";
    cin>>arr3[i];
}
for (int i = 0; i < n; i++)
{
    for (int j = i+1; j < n; j++)
    {
        if(arr2[i]>arr2[j])
        {
                int temp;
                temp = arr3[j];
                arr3[j] = arr3[i];
                arr3[i] = temp;
                temp = arr2[j];
                arr2[j] = arr2[i];
                arr2[i] = temp;
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
    }
    
}
int sum;
wait[0] = 0;
sum = arr3[0];
for (int i = 1; i < n; i++)
{   wait[i] =sum= sum - arr2[i]+arr2[i-1];
    sum = sum + arr3[i];
}
}
cout<<"Process"<<" "<<"Arrival Time"<<" "<<"CPU Time"<<" "<<"Waiting Time"<<endl;
for(int i=0;i<n;i++){
    cout<<arr[i]<<"     "<<arr2[i]<<"       "<<arr3[i]<<"        "<<wait[i]<<endl;
}
}