// This code is made by Lovedeep singh
#include <bits/stdc++.h>
using namespace std;
class fnode
{
public:
    int value;
    bool ooc;
    int store(int val, bool oc)
    {
        value = val;
        ooc = oc;
    }
};
class node
{
public:
    int value;
    int index;
    int free(int i, int val)
    {
        index = i;
        value = val;
    }
};

int main()
{
    int n=0,l;
    cout << "Enter Number of spaces = ";
    cin >> l;
    fnode fnod[l];
    int val;
    bool oc;
    int in;
    for (int i = 0; i < l; i++)
    {
        cout<<"Enter memory size of "<<i+1<<" = ";
        cin >> val;
        cout<<"if it is occupied enter 1 if it is free enter 0 "<<i+1<<" = ";
        cin >> oc;
        if(oc==0)
        {
            n++;
        }
        fnod[i].store(val, oc);
    }

    node nod[n];
    int k = 0;
    for (int i = 0; i < l; i++)
    {
        if (fnod[i].ooc == 0)
        {
            nod[k].free(i + 1, fnod[i].value);
            k++;
        }
    }

    int r;
    cout << "enter requirement = ";
    cin >> r;
    for (int i = 0; i < n; i++)
    {
        if (nod[i].value >= r)
        {
            cout << "FF => Index = " << nod[i].index << " Capacity = " << nod[i].value << endl;
            break;
        }
    }
    int min = 35;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (nod[i].value >= r)
        {
            int m = nod[i].value - r;
            if (m < min)
            {
                min = m;
                j = i;
            }
        }
    }
    cout << "BF => Index = " << nod[j].index << " Capacity = " << nod[j].value << endl;
    int max = 0;
    j = 0;
    for (int i = 0; i < n; i++)
    {
        if (nod[i].value >= r)
        {
            int mx;
            mx = nod[i].value - r;
            if (mx > max)
            {
                max = mx;
                j = i;
            }
        }
    }
    cout << "WF => Index = " << nod[j].index << " Capacity = " << nod[j].value << endl;
}