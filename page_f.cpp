// This code is made by Lovedeep singh
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> m = {7, 0, 2, 1, 5, 2, 0, 3, 0, 4, 6, 0};
    int n;
    cout << "Enter the number of slots ";
    cin >> n;
    vector<int> v;
    bool run = true;
    int i = 0;
    int j =0;
    while (run)
    {
        if (v.empty())
        {
            v.push_back(m[i]);
            cout << "Page fault at = "<<m[i] << endl;
            i++;
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
            v[j]=m[i];
            i++;
            j++;
        }
        else
        {
            cout << "Page fault at = "<<m[i]<< endl;
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
    for (int  k= 0; k < v.size(); k++)
    {
        cout << v[k] << " ";
    }
    
}