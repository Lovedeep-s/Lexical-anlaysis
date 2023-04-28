//This code is made by Lovedeep singh
#include<bits/stdc++.h>
using namespace std;
int main()
{
vector<int> m = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 3 };
int n;
cout<<"Enter the number of slots ";
cin>>n;
vector<int> v;

bool run = true;
int i = 0;
    int j =0;
int m1= 0;
int h=0;
int y=0;
    while (run)
    {
        if (v.empty())
        {
            v.push_back(m[i]);
            cout << "Page fault at = "<<m[i] << endl;
            i++;
            y++;
            continue;
        }

        if (find(v.begin(), v.end(), m[i]) != v.end())
        {
            cout << "Page hit" << endl;
              i++;
            
        }
        else if (v.size() == n)
        {
            cout << "Page fault at = "<<m[i] << endl;
            y++;
            for (int k = 0; k<v.size(); k++)
            {
                int min;
                min= find(m.begin()+i, m.end(), v[k]) -m.begin();
                
                if(m1 < min)
                {
                    m1=min;
                    h=k;
                }
                // cout<<m1<<endl;
            }
            if(m1!=0)
            j=h;
            
            m1=0;
            v[j]=m[i];
            i++;
            j++;
        }
        else
        {
            cout << "Page fault at = "<<m[i]<< endl;
            y++;
            v.push_back(m[i]);
            i++;
        }
        if (m.size() == i)
        {
            run = false;
        }if(j==n){
            j=0;
        }

    }
    cout<<"No. of page fault = "<<y<<endl;
    cout<<"No. of page hit = "<<m.size()-y<<endl;
    for (int  k= 0; k < v.size(); k++)
    {
        cout << v[k] << " ";
    }
}