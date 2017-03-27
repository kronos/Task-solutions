#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
#include <sstream>
#include <queue>
using namespace std;
string s="";
int n,p=1;
bool prime(int p)
{
    if (p==2)
        return true;
    if (p%2==0)
        return false;
    int pr = sqrtf(p);
    bool f = true;
    for(int i=3;(i<=pr)&&(f);i++)
    {
        f = p%i!=0;
    }
    return f;
}

int gen(int p)
{
    while (!prime(p))
        p++;
    return p;
}

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int m[100][100],mm;
    int n,q;
    cin >> n >> mm;
    for (int i=0;i<n;i++)
        for (int j=0;j<mm;j++)
        {
            cin >> m[i][j];
        }
    int down=-1001,up=1001;
    int i,j;
    for (i=0;i<n;i++)
    {
        q = m[i][0];
        for (j=1;j<mm;j++)
        {
            if (m[i][j]<q)
                q = m[i][j];
        }
        if (q>down)
            down = q;
    }
    for (j=0;j<mm;j++)
    {
        q = m[0][j];
        for (i=1;i<n;i++)
        {
            if (m[i][j]>q)
                q = m[i][j];
        }
        if (q<up)
            up = q;
    }
    cout << down << " " << up;
    return 0;
}
