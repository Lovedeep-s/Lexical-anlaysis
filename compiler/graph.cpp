//This code is made by Lovedeep singh
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,edges;
    cout<<"Enter number of vertices = ";
    cin>>n;
    int a[n][n] ;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j]=0;
        }
        
    }
    cout<<"Enter number of edges = ";
    cin>>edges;
    int s,e,v;
    for (int i = 0; i < edges; i++)
    {
        cout<<"enter start vertices = ";
        cin>>s;
        cout<<"enter end vertices = ";
        cin>>e;
        cout<<"enter weight = ";
        cin>>v;
        a[s-1][e-1]=v;
    }
    cout<<"Adjacency matrix is = "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<endl;
        for (int j = 0; j < n; j++)
        {
            
            cout<<a[i][j]<<" ";
        }
        
    }
    cout<<endl;
    return 0;

    
    

}