//This code is made by Lovedeep singh
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> m = {62 ,12,100,119,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int s = 1;
    int e=120;
    int c = 92;
    sort(m.begin(),m.end());
    cout<<"Hit sequence is ->> "<<c<<" -> ";
    while (!m.empty())
    {
        for (int i = 0; i < m.size(); i++)
        {
            if(c<m[i])
            {
                c=m[i];
                cout<<m[i]<<" -> ";
                m.erase(m.begin()+i);
                break;
            }
            else if(c==m[i])
            {
                cout<<m[i]<<" -> ";
                m.erase(m.begin()+i);
                break;
            }
            else if(i==m.size()-1)
            {
                c=m[i];
                cout<<m[i]<<" -> ";
                m.erase(m.begin()+i);
                break;
            }
        }
        
        
    }
    cout<<"End"<<endl;

}