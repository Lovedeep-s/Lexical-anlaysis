//This code is made by Lovedeep singh
#include<bits/stdc++.h>
using namespace std;
int main(){
    string filename = "inputg.txt";
    ifstream file;
    file.open(filename.c_str());
    int n,edges;
    file>>n;
    int a[n][n] ;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) 
        {
            a[i][j]=0;
        }
        
    }
    file>>edges;
    int s,e,v;
    for (int i = 0; i < edges; i++)
    {
        file>>s;
        file>>e;
        file>>v;
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
    file.close();
    return 0;


}