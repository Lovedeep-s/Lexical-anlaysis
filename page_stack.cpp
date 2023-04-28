// This code is made by Lovedeep singh
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> m = {1, 2, 1, 0, 3, 0, 1, 2};
    int n;
    cout << "Enter the number of slots ";
    cin >> n;
    vector<int> v;
    bool run = true;
    int i = 0;
    int j = 0;
    while (run)
    {
        if (v.empty())
        {
            v.push_back(m[i]);
            cout << "Page fault at = " << m[i] << endl;
            i++;
            continue;
        }

        if (find(v.begin(), v.end(), m[i]) != v.end())
        {
            cout << "Page hit at = " << m[i] << endl;
            v.erase(find(v.begin(), v.end(), m[i]));
            v.push_back(m[i]);
            i++;
        }
        else if (v.size() == n)
        {
            cout << "Page fault at = " << m[i] << endl;
            v.erase(v.begin());
            v.push_back(m[i]);
            i++;
            j++;
        }
        else
        {
            cout << "Page fault at = " << m[i] << endl;
            v.push_back(m[i]);
            i++;
        }
        if (m.size() == i)
        {
            run = false;
        }
        if (j == n)
        {
            j = 0;
        }

        // for (int  k= 0; k < v.size(); k++)
        // {
        //     cout << v[k] << " ";
        // }
    }
    for (int k = 0; k < v.size(); k++)
    {
        cout << v[k] << " ";
    }
}