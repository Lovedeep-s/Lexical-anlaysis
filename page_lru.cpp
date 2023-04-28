//This code is made by Lovedeep singh
#include<bits/stdc++.h>
using namespace std;
int main()
{
vector<int> m = {6, 1, 1, 2, 0, 3, 4, 6, 0, 2, 1, 2, 1, 2, 0, 3, 2, 1, 2, 0};
int n;
cout<<"Enter the number of slots ";
cin>>n;
vector<int> v;
vector<int> v1;
bool run = true;
int i = 0;
int j =0;
int h=0;
int o=0;
int l=0;
int y=0;
while (run)
    {
        if (v.empty())
        {
            v.push_back(m[i]);
            cout << "Page fault at = "<<m[i] << endl;
            v1.push_back(l);
            i++;
            l++;
            y++;
            continue;
        }

        if (find(v.begin(), v.end(), m[i]) != v.end())
        {
            cout << "Page hit" << endl;
            h = find(v.begin(), v.end(),m[i]) - v.begin();
            // cout<<"h = "<<h<<endl;
            v1[h]=l;
              i++;
            
        }
        else if (v1[j]==0&&v.size() == n)
        {
            cout << "Page fault at = "<<m[i] << endl;
            v[j]=m[i];
            v1[j]=l;
            y++;
            i++;
            j++;
        }
        else if (v.size() == n&&v1[j]!=0)
        {
            cout << "Page fault at = "<<m[i] << endl;
            o = min_element(v1.begin(), v1.end()) - v1.begin();
            j=o;
            // cout<<"j = "<<j<<endl;
            v[j]=m[i];
            v1[j]=l;
            y++;
            i++;
            j++;
        }
        else
        {
            cout << "Page fault at = "<<m[i]<< endl;
            v.push_back(m[i]);
            v1.push_back(l);
            y++;
            i++;
        }
        if (m.size() == i)
        {
            run = false;
        }if(j==n){
            j=0;
        }
        l++;

    }
    cout<<"No. of page fault = "<<y<<endl;
    cout<<"No. of page hit = "<<m.size()-y<<endl;
    for (int  k= 0; k < v.size(); k++)
    {
        cout << v[k] << " ";
    }
    
}