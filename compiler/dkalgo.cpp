// This code is made by Lovedeep singh
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
            if (adj[n][i] != 0&&v[i].known==0)
            {
                v[i].dist = adj[n][i] + v[n].dist;
                v[i].parent = n;
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
    for (int i = 0; i < 7; i++)
    {
        cout << i + 1 << " " << v[i].known << " " << v[i].dist << " " << v[i].parent+1 << endl;
    }
}

int main()
{

    shortestpath();
}