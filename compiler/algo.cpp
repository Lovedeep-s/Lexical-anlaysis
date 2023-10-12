#include <bits/stdc++.h>
using namespace std;

class nodes
{
public:
    int known;
    int dist;
    int parent;
    nodes()
    {
        known = 0;
        dist = INT_MAX;
        parent = -1;
    }
};

void shortestpath()
{
    int n = 0;
    int adj[7][7] = {
        {0, 2, 0, 1, 0, 0, 0},
        {0, 0, 0, 3, 10, 0, 0},
        {4, 0, 0, 0, 0, 5, 0},
        {0, 0, 2, 0, 2, 8, 4},
        {0, 0, 0, 0, 0, 0, 6},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0}};
    nodes v[7];
    v[n].dist = 0;

    for (int j = 0; j < 7; j++)
    {
        v[n].known = 1;

        for (int i = 0; i < 7; i++)
        {
            if (adj[n][i] != 0 && v[i].known == 0)
            {
                if (v[n].dist + adj[n][i] < v[i].dist)
                {
                    v[i].dist = v[n].dist + adj[n][i];
                    v[i].parent = n;
                }
            }
        }

        int m = INT_MAX;
        for (int i = 0; i < 7; i++)
        {
            if (m > v[i].dist && v[i].known == 0)
            {
                m = v[i].dist;
                n = i;
            }
        }
    }
    cout << "G" << "\t";
    for (int i = 0; i < 7; i++)
    {
        cout << i+1 <<"\t";
    }
    cout << endl;
    
    for (int i = 0; i < 7; i++)
    {
        cout << i+1 << "\t";
        for (int j = 0; j < 7; j++)
        {
            if(adj[i][j]!=0)
            {
            cout << adj[i][j] <<"\t";
            }
            else{
                cout<<"∞"<<"\t";
            }
        }
        cout << endl;
        
    }
 cout <<"node"<<"\t"<<"known"<<"\t"<<"dist"<<"\t"<<"parent"<<endl; 
    for (int i = 0; i < 7; i++)
    {
       
        cout << i + 1 << "\t" << v[i].known << "\t" << v[i].dist << "\t" << v[i].parent + 1 << endl;
    }
}

int main()
{
    shortestpath();
}
