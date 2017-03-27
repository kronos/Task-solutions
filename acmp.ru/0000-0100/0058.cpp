#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <stack>

using namespace std;
const double pi = 3.14159265358979323;
int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int t,i,j,n,m,p;
    int x[100][100];
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for (i=0;i<n;i++)
            for (j=0;j<m;j++)
                cin >> x[i][j];
        bool f = true;
        for (i=0;(i<=n-2)&&(f);i++)
            for (j=0;(j<=m-2)&&(f);j++)
            {
                p = x[i][j]+x[i+1][j]+x[i][j+1]+x[i+1][j+1];
                f = (p>0) && (p<4);
            }
        if (f)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}
