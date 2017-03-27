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
    int n,i,j,k;
    cin >> n;
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            cin >> a[i][j];
    int mmax = 0;
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            for (k=0;k<n;k++)
            {
                if (a[j][i]!=-1 && a[i][k]!=-1)
                {
                    if (a[j][k]!=-1)
                        a[j][k] = min(a[j][k],a[j][i]+a[i][k]);
                    else
                        a[j][k] = a[j][i]+a[i][k];
                }
            }
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            mmax = max(a[i][j],mmax);
    cout << mmax;
    return 0;
}
