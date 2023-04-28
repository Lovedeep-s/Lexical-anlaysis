//This code is made by Lovedeep singh
#include<bits/stdc++.h>
using namespace std;
class a{
    public:
    int value;
    int request;
    int f;
};
class b{
    public:
    int value;
    int request;
    int f;
};
class c{
    public:
    int value;
    int request;
    int f;
};
int main(){
    int n=5;
    a a1[n];
    b b1[n];
    c c1[n];
    int allocate[n][n]={
        {0,1,0},{2,0,0},{3,0,3},{2,1,1},{0,0,2}
    };
    
for (int i = 0; i < n; i++)
{
    a1[i].value = allocate[i][0];
    b1[i].value = allocate[i][1];
    c1[i].value = allocate[i][2];
}

int available[]= {0,0,0};
int request[n][n]={
       {0,0,0},{2,0,2},{0,0,0},{1,0,0},{0,0,2}
    };
    vector<string> v;
for (int i = 0; i < n; i++)
{
    a1[i].request=request[i][0];
    b1[i].request=request[i][1];
    c1[i].request=request[i][2];
    a1[i].f=0;
    b1[i].f=0;
    c1[i].f=0;
    string temp = "P";
        temp.push_back(i + '1');
        v.push_back(temp);
}
cout<<"Allocated"<<" "<<"Request"<<endl;
cout<<"   "<<"A"<<" "<<"B"<<" "<<"C"<<"  "<<"A"<<" "<<"B"<<" "<<"C"<<endl;
for (int i = 0; i < n ; i++)
{
    cout<<v[i]<<" "<<a1[i].value<<" "<<b1[i].value<<" "<<c1[i].value<<"  "<<a1[i].request<<" "<<b1[i].request<<" "<<c1[i].request<<endl;
}
cout<<"Available"<<endl<<" "<<"A"<<" "<<"B"<<" "<<"C"<<endl;
cout<<" "<<available[0]<<" "<<available[1]<<" "<<available[2]<<endl;

int j=0;
bool run = true;
int count=0;
int c=0;
while (run)
{

    if(a1[j].request<=available[0]&&b1[j].request<=available[1]&&c1[j].request<=available[2]&&a1[j].f!=1)
    {
        available[0]=available[0]+a1[j].value;
        available[1]=available[1]+b1[j].value;
        available[2]=available[2]+c1[j].value;
        a1[j].value=0;
        b1[j].value=0;
        c1[j].value=0;
        a1[j].request=0;
        b1[j].request=0;
        c1[j].request=0;
        a1[j].f=1;
        b1[j].f=1;
        c1[j].f=1;
        count=0;
        c++;
    }
    else
    {
        count++;
    }
    j++;
    
    if (c==n)
    {
        run = false;
        cout<<"allocation passed";
    }
    if (count==n)
    {
        run =false;
        cout<<"allocation failed";
    }
    if(j==n)
    {
        j=0;
    }
}


}