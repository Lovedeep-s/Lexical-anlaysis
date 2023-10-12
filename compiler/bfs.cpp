//This code is made by Lovedeep singh
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[4][4] = {{0,1,0,0},{0,0,1,0},{0,0,0,1},{0,0,0,0}};
    for (int i = 0; i < 4; i++)
    {
        cout<<endl;
        for (int j = 0; j < 4; j++)
        {
            cout<<a[i][j]<<" ";
        }
    }
    
    int status[4] = {1,1,1,1};
    int queue[4]={-1,-1,-1,-1};
    int stv ;
    int f= -1;
    int r= -1;
    cout<<"Enter starting vertex = ";
    cin>>stv;
    queue[++r] = stv;
    status[stv] = 2;
    f=0;    
    int n=0;
    while(f<=r)
    {
        int v = queue[f];
        f++;
        cout<<v<<" ";
        for (int i = 0; i < 4; i++)
        {
            if(a[v][i]==1 && status[i]==1)
            {
                queue[++r] = i;
                status[i] = 2;
            }
        }
        status[v] = 3;
        n++;
    }
    cout<<n;
    // for (int i = 0; i < 4; i++)
    // {
    //     cout<<status[i]<<" ";
    // }
    


}