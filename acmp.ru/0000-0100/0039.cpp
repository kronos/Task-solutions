#include <iostream>
//#include <math.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
//#include <fstream>
#include <map>
#include <sstream>
#include <stack>

using namespace std;
const double pi = 3.14159265358979323;
int m[102],n,z[101][101];

int _get(int k, int p)
{
    if (z[k][p]!=0)
        return z[k][p];
    if (k==n)
        return m[k]*p;
    int &a = z[k][p];
    a = max(a,_get(k+1,p+1));
    a = max(a,_get(k+1,1)+m[k]*p);

    return a;
}

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int a=0,c;
    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> m[i];
    cout << _get(1,1);
    return 0;
}
