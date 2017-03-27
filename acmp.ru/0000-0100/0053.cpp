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
    int n,m;
    cin >> n >> m;

    int g=0,r=0,blu=0,bla=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if (i*j%5==0)
                blu++;
            else  if (i*j%3==0)
                g++;
            else  if (i*j%2==0)
                r++;
            else
                bla++;
        }

    cout << " RED : "<< r << endl;
    cout << " GREEN : "<< g << endl;
    cout << " BLUE : "<< blu << endl;
    cout << " BLACK : "<< bla << endl;
    return 0;
}
