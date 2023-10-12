// This code is made by Lovedeep singh
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i;
    cout << "Enter number of nodes = "; // input from user about number of nodes
    cin >> i;
    vector<string> v;
    int arr[50][50];
    for (int k = 0; k < i; k++)
    {
        for (int l = 0; l < i; l++)
        {
            cout << "Enter value of " << k << " " << l << " = ";
            cin >> arr[k][l];//take imput of adajency matrix of graph
        }

        string temp = "P";// i am naming the process as P1,P2,P3,P4,P5 and etc
        temp.push_back(k + '1');
        v.push_back(temp);
    }
    cout << "G" << " ";
    for (int k = 0; k < i; k++)
    {
        cout << v[k] << " ";
    }
    cout << endl;

    for (int k = 0; k < i; k++)
    {   
        cout << v[k] << " ";
        for (int l = 0; l < i; l++)
        {
            cout << arr[k][l] << "  ";
        }
        cout << endl;// pint the intial matrix
    }
    

    int n;
    cout << "Enter number of new = ";// input for new process or nodes in graph
    cin >> n;
    int a, b, c;
    for (int k = 0; k < n; k++)
    {
        cout << "Enter value of a and b = ";
        cin >> a >> b;//take input about the connection of new process with old process
        arr[a][b] = 0;
        arr[b][a] = 0;
        for (int k = 0; k < i + 1; k++)
        {
            for (int h = 0; h < i + 1; h++)
            {
                if (h == b && k == i)
                {
                    arr[k][h] = 1;
                }
                else if (h == i && k == a)
                {
                    arr[k][h] = 1;
                }
                else if (h == i || k == i)
                {
                    arr[k][h] = 0;
                }
            }
        }// updating the matrix with new nodes
        i++;
        
    }
    for (int h = 0; h < n; h++)
        {

            string temp = "R";
            temp.push_back(h + '1');

            v.push_back(temp);//naming the new process as R1,R2,R3,R4 and etc
        }

        
    cout << "G" << " ";
    for (int k = 0; k < i; k++)
    {
        cout << v[k] << " ";
    }
    cout << endl;

    for (int k = 0; k < i; k++)
    {   
        cout << v[k] << " ";
        for (int l = 0; l < i; l++)
        {
            cout << arr[k][l] << "  ";// we are printing the final matrix
        }
        cout << endl;
    }
}