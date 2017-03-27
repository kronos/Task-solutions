#include <iostream>

using namespace std;
int i,n,ans,j,m;
int a[1000],L[1000];
int main()
{
   freopen("input.txt", "rt", stdin);
   freopen("output.txt", "wt", stdout);
   cin >> n;
   for (i=0;i<n;i++)
      cin >> a[i];
   L[0] = 1;
   ans = 1;
   for (i=1;i<n;i++)
   {
      m = 0;
      for (j=0;j<i;j++)
     if (L[j]>m && a[j]<a[i])
        m = L[j];
      L[i] = m+1;
      if (m+1>ans)
     ans = m+1;
   }
   cout << ans;
   return 0;
}
