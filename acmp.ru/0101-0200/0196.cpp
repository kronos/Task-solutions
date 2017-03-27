#include <iostream>
using namespace std;
int a[100][100];
int main()
{
   freopen("input.txt", "rt", stdin);
   freopen("output.txt", "wt", stdout);
   int N,l,r,t,b,i,j,c=1,d=0;
   cin >> N;
   l = 0;
   r = N-1;
   t = 0;
   b = N-1;
   i = 0;
   j = 0;
   while (l<r || t<b)
   {
      switch(d)
      {
     case 0:
        for(j=l;j<=r;j++)
           a[i][j] = c++;
        j--;
        t++;
     break;
     case 1:
        for(i=t;i<=b;i++)
           a[i][j] = c++;
        r--;
        i--;
     break;
     case 2:
        for(j=r;j>=l;j--)
           a[i][j] = c++;
        b--;
        j = l;
     break;
     case 3:
        for(i=b;i>=t;i--)
           a[i][j] = c++;
        l++;
        i = t;
     break;
      }
      d++;
      d%=4;
   }
   a[t][l] = c;
   for(i=0;i<N;i++)
   {
      for(j=0;j<N;j++)
     cout << a[i][j] << " ";
      cout << endl;
   }
   return 0;
}
