// This code is made by Lovedeep singh
#include <bits/stdc++.h>
using namespace std;
class fnode
{
public:
    int value;
    bool ooc;
    int store(int val, bool oc)// store value of memory slot size and the memory slot is occupied or not
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
    int free(int i, int val)// store value of free memory slot size and the memory slot index
    {
        index = i;
        value = val;
    }
};

int main()
{
    int n=0,l;
    cout << "Enter Number of spaces = ";// input form user about number of memory slots
    cin >> l;
    fnode fnod[l];
    int val;
    bool oc;
    int in;
    for (int i = 0; i < l; i++)
    {
        cout<<"Enter memory size of "<<i+1<<" = ";
        cin >> val;//input from user about memory slot size
        cout<<"if it is occupied enter 1 if it is free enter 0 "<<i+1<<" = ";
        cin >> oc;// whether it is occupied or not
        if(oc==0)
        {
            n++;//keeping count of free spaces
        }
        fnod[i].store(val, oc);// storing the value in the class
    }

    node nod[n];
    int k = 0;
    for (int i = 0; i < l; i++)
    {
        if (fnod[i].ooc == 0)//we checking if slot is free or not   
        {
            nod[k].free(i + 1, fnod[i].value);// storing the free slot information in the class node
            k++;
        }
    }

    int r;
    cout << "enter requirement = ";//we ask user for his memory requirement
    cin >> r;
    for (int i = 0; i < n; i++)//triverse through the free memory slots and first slot which is greater than or equal to the requirement is the first fit
    {
        if (nod[i].value >= r)
        {
            cout << "FF => Index = " << nod[i].index << " Capacity = " << nod[i].value << endl;
            break;
        }
    }
    int min = 35;
    int j = 0;
    for (int i = 0; i < n; i++)//triversing throught all free slots
    {
        if (nod[i].value >= r)// checking that slot is bigger or equal to the requirement
        {
            int m = nod[i].value - r;
            if (m < min)// finding the minimum wastage in the slot allocation
            {
                min = m;
                j = i;// selecting the slot
            }
        }
    }
    cout << "BF => Index = " << nod[j].index << " Capacity = " << nod[j].value << endl;//printing the best fit slot for the requirement
    int max = 0;
    j = 0;
    for (int i = 0; i < n; i++)//triversing the free slots
    {
        if (nod[i].value >= r)//checking the slot is bigger or equal to the requirement
        {
            int mx;
            mx = nod[i].value - r;
            if (mx > max)//finding the biggest wastage in the slot allocation
            {
                max = mx;
                j = i;//allocating the slot
            }
        }
    }
    cout << "WF => Index = " << nod[j].index << " Capacity = " << nod[j].value << endl;//printing the worst fit slot for the requirement
    }