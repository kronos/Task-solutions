#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
#include <sstream>
#include <queue>
//#include <fstream>
using namespace std;
//ifstream in("input.txt");
//ofstream out("output.txt");
int m[20][20];
int N;
void rec(int i, int j, int k)
{
    if (i<0 || j<0 || i>=N || j>=N || m[i][j]<=k)
        return;

    m[i][j] = k;

    rec(i-2,j+1,k+1);
    rec(i-2,j-1,k+1);

    rec(i+2,j+1,k+1);
    rec(i+2,j-1,k+1);

    rec(i-1,j+2,k+1);
    rec(i+1,j+2,k+1);

    rec(i-1,j-2,k+1);
    rec(i+1,j-2,k+1);
}
int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int i,j;
    cin >> N;
    int x1,y1,x2,y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    x1--;y1--;
    x2--;y2--;
    for (i=0;i<N;i++)
        for (j=0;j<N;j++)
        {
            m[i][j] = 60000;
        }

    rec(x2,y2,0);
    cout << m[x1][y1];
    return 0;
}
