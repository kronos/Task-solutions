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
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int N,S,i,j,m[100][100];
    cin >> N >> S;
    for (i=0;i<N;i++)
        for (j=0;j<N;j++)
            cin >> m[i][j];
    int q;
    for (i=0;i<N;i++)
        for (j=0;j<N;j++)
        {
            q = 0;
            for (int k=0;k<N;k++)
            {
                q+=m[i][k]*m[k][j];
            }
            m[i][j] = q>0 ? 1 : 0;
        }
    q = 0;
    for (j=0;j<N;j++)
        if (m[S-1][j]==1 && j!=S-1)
            q++;
    cout << q;
    return 0;
}
