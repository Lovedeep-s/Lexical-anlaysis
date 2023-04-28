//This code is made by Lovedeep singh
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> m = {62 ,12,100,119,2};
    int s = 1;
    int e=120;
    int c = 92;
    int min=0;
    int m1= INT_MAX;
    int j=0;
    cout<<endl;
    cout<<"Hit sequence is ->> "<<c<<" -> ";
    while (!m.empty())
    {
        for(int i=0;i<m.size();i++)
        {
            min = abs(m[i]-c);
            if(m1>min)
            {
                m1=min;
                j=i;
                
            }
            min=0;

        }
        c=m[j];
        cout<<m[j]<<" -> ";
        m.erase(m.begin()+j);
        m1=INT_MAX;

    }
    cout<<"End"<<endl;

}
