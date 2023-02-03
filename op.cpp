//This code is made by Lovedeep singh
#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int arr[n];
int arr2[n];
int arr3[n];
for(int i=0;i<n;i++){
    cout<<"input the arrival time of process "<<i+1<<" = ";
    cin>>arr2[i];
    arr3[i]=arr2[i];
}

for(int i=0;i<n;i++){
    cout<<"input the cpu time of process "<<i+1<<" = ";
    cin>>arr[i];
}
vector<int> m;

int i, j, min, temp=0;
   for (i = 0; i < n - 1; i++) {
      min = i;
      for (j = i + 1; j < n; j++)
      if (arr3[j] < arr3[min])
      min = j;
      temp = arr3[i];
      arr3[i] = arr3[min];
      arr3[min] = temp;
   }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr3[i]==arr2[j]){
                m.push_back(j);
            }
        }
    
    }
int *wait = new int[n+1];
// for(auto i=m.begin();i!=m.end();i++){
//     cout<<*i<<" ";
// }
auto h=m.begin();
wait[*h] = 0;
cout<<wait[1];
h++;
int y;
for(;h!=m.end();h++){
    if ((arr2[*h]-arr[*(h-1)]-arr2[*(h-1)])>=0)
    {
        y=0;
    }
    else
    {
        y= abs((arr2[*h]-arr[*(h-1)]-arr2[*(h-1)]));
    }
    int t;
    for (int i = 0; i < n; i++)
    {
        if (m[i]==*h)
        {
            t=i;
        }
        else
        {
            t=0;
        }
    }
    if(t>1)
    {
        for (int i = 0; i < t; i++)
        y = y +arr[m[i]];
    }
    }
    cout<<y<<endl;
    wait[*h]=y;

cout<<"Process"<<" "<<"CPU Time"<<" "<<"Waiting Time"<<endl;
for(int i=0;i<n;i++){
    cout<<i+1<<" "<<arr[i]<<" "<<wait[i]<<endl;
}
}

