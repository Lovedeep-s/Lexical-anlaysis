// This code is made by Lovedeep singh
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int value;
    int index;
    int free(int val)
    {
        value = val;
    }
};
int main()
{
    int n;
    cout << "Enter Number of free spaces = ";
    cin >> n;
    node nod[n];
    int val;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        nod[i].free(val);
    }
    int r;
    cout << "enter requirement = ";
    cin >> r;
    for (int i = 0; i < n; i++)
    {
        if (nod[i].value >= r)
        {
            cout <<"FF => Index = "<<i+1<<" Capacity = "<< nod[i].value<<endl;
            break;
        }
    }
    int min = 35;
    int j=0;
    for (int i = 0; i < n; i++)
    {
        if (nod[i].value >= r)
        {
            int m = nod[i].value - r;
            if (m < min)
            {
                min = m;
                j=i;

            }
        }
    }
    cout <<"BF => Index = "<<j+1<<" Capacity = "<< nod[j].value<<endl;
    int max = 0;
    j=0;
    for (int i = 0; i < n; i++)
    {
        if (nod[i].value >= r)
        {
            int  mx;
            mx = nod[i].value - r;
            if (mx > max)
            {
                max = mx;
                j=i;
            }
        }
    }
    cout <<"WF => Index = "<<j+1<<" Capacity = "<< nod[j].value<<endl;
}