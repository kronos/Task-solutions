#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int a[200000];
map<int,int> t;
map<int,int>::iterator it;
int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int i,j,n;
    cin >> n;
    for (i=0;i<n;i++)
    {
        cin >> a[i];
        t[a[i]]++;
    }
    int mmin=0,nmin;
    for (it=t.begin();it!=t.end();it++)
    {
        if (it->second>mmin)
        {
            mmin = it->second;
            nmin = it->first;
        }
    }
    for (i=0;i<n;i++)
    {
        if (a[i]!=nmin)
            cout << a[i] << " ";
    }
    for (i=0;i<mmin;i++)
        cout << nmin << " ";
    return 0;
}
