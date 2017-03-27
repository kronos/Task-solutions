#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
#include <sstream>
#include <queue>
using namespace std;
int a[100][100];
int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int n,i,j,k,x,y;
    cin >> n;
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            cin >> a[i][j];
    cin >> x >> y;
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            for (k=0;k<n;k++)
            {
                if (a[j][i]!=0 && a[i][k]!=0 && j!=k)
                {
                    if (a[j][k]!=0)
                        a[j][k] = min(a[j][k],a[j][i]+a[i][k]);
                    else
                        a[j][k] = a[j][i]+a[i][k];
                }
            }
    x--;
    y--;
    if (x==y)
        cout << 0;
    else
    {
        if (a[x][y])
            cout << a[x][y];
        else
            cout << -1;
    }
    return 0;
}
