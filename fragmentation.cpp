// This code is made by Lovedeep singh
#include <bits/stdc++.h>
using namespace std;
void randomList(int m, int n, int *arr)
{

    srand(time(0));

    for (int i = 0; i < n; i++)
    {

        arr[rand() % m]++;
    }
    for (int i = 0; i < m; i++)
    {
        cout << "The size of block " << i + 1 << " = " << arr[i] << endl;
    }
}

int main()
{
    int n, h;
    cout << "Enter the number of blocks and the size of total block = ";
    cin >> n >> h;

    int a[n] = {0};
    randomList(n, h, a);
    cout << "The number of occupied blocks are = ";
    int y, k;
    cin >> y;
    vector<int> occupied;
    for (int i = 0; i < y; i++)
    {
        cout << "Enter the occupied block number = ";
        cin >> k;
        occupied.push_back(k - 1);
    }
    vector<float> internal;
    cout << "External fragmentation is = " << endl;
    for (int i = 0; i < n; i++)
    {
        if (find(occupied.begin(), occupied.end(), i) == occupied.end())
        {

            cout << "the external fargmentation block " << i + 1 << " = " << a[i] << endl;
        }
        else if ((i + 1) % 2 == 0)
        {
            internal.push_back(a[i] * 0.02);
        }
        else
        {
            internal.push_back(a[i] * 0.01);
        }
    }
    cout << "Internal fragmentation is = " << endl;
    for (int i = 0; i < internal.size(); i++)
    {
        cout << "The internal fragmentation of block " << occupied[i] + 1 << " = " << internal[i] << endl;
    }
}