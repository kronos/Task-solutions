#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <math.h>
#include <map>

using namespace std;
bool a[101][101];
int main()
{
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
    int n,k,x,y,i,j,kk;
    cin >> n >> kk;
    cin >> x;
    while (x)
    {
        cin >> y;
        a[x][y] = true;
        cin >> x;
    }

    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            for (k=1;k<=n;k++)
                a[j][k] = a[j][k] || (a[j][i] && a[i][k]);

    bool f = true;
    a[kk][kk] = true;
    for (i=1;(i<=n)&&(f);i++)
        f = a[kk][i];
    if (f)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
