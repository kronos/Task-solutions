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
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            for (k=0;k<n;k++)
                a[j][k] = min(a[j][k],a[j][i]+a[i][k]);
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
    return 0;
}
