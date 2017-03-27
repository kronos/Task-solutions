#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int ans;
int table[70][70];
unsigned long long int p[70][70];
int n,m;
unsigned long long int rec(int i, int j)
{
    if (i>=n || j>=m)
    {
        return 0;
    }
    if (p[i][j]!=-1)
        return p[i][j];

    if (table[i][j]==0)
    {
        if (i==n-1 && j==m-1)
            p[i][j] = 1;
        else
            p[i][j] = 0;
    }else
        p[i][j] = rec(i+table[i][j],j)+rec(i,j+table[i][j]);

    return p[i][j];
}
int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    cin >> n >> m;
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            cin >> table[i][j];
            p[i][j]=-1;
        }
    cout << rec(0,0);
    return 0;
}
