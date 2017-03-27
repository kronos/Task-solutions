#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
#include <sstream>
#include <queue>
using namespace std;

int main()
{
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
    int x1,y1,x2,y2,x3,y3;
    int ax,ay;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;

    if ((x1-x2)*(x1-x3)+(y1-y2)*(y1-y3)==0)
    {
        ax = x2+x3-x1;
        ay = y2+y3-y1;
    }
    else if ((x2-x1)*(x2-x3)+(y2-y1)*(y2-y3)==0)
    {
        ax = x1+x3-x2;
        ay = y1+y3-y2;

    }
    else
    {
        ax = x1+x2-x3;
        ay = y1+y2-y3;
    }

    cout << ax << ' ' << ay;
    return 0;
}
