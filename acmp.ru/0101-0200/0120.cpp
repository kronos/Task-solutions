#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
#include <sstream>
#include <queue>
using namespace std;
int table[20][20];

int main()
{
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
    int n,m,i,j;
    cin >> n >> m;
    for (i=0;i<n;i++)
        for (j=0;j<m;j++)
            cin >> table[i][j];
    for (j=1;j<m;j++)
        table[0][j]+= table[0][j-1];
    for(i=1;i<n;i++)
    {
        table[i][0]+=table[i-1][0];
        for (j=1;j<m;j++)
            table[i][j]+=min(table[i-1][j],table[i][j-1]);
    }
    cout << table[n-1][m-1];
    return 0;
}
