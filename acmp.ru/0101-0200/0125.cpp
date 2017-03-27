#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
#include <sstream>
#include <queue>

using namespace std;
int i,n,ans,j,m;
int bridge[100][100];
int color[100];
int main()
{
   freopen("input.txt", "rt", stdin);
   freopen("output.txt", "wt", stdout);
   cin >> n;
   for (i=0;i<n;i++)
      for (j=0;j<n;j++)
     cin >> bridge[i][j];

   for (i=0;i<n;i++)
      cin >> color[i];

   for (i=0;i<n;i++)
      for (j=i+1;j<n;j++)
     if (bridge[i][j] && color[i]!=color[j])
        ans++;
   cout << ans;
   return 0;
}
