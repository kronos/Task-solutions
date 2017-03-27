#include <iostream>

using namespace std;
int i,ans=1000000,n;
int W[18];
void rec(int i, int w1, int w2)
{
   if (i==n)
      ans = min((int)labs(w1-w2),ans);
   else
   {
      rec(i+1,w1+W[i],w2);
      rec(i+1,w1,w2+W[i]);
   }
}
int main()
{
   freopen("input.txt", "rt", stdin);
   freopen("output.txt", "wt", stdout);
   cin >> n;
   for (i=0;i<n;i++)
      cin >> W[i];
   rec(0,0,0);
   cout << ans;
   return 0;
}
