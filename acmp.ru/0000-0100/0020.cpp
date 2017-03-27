#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
#include <sstream>
#include <queue>

using namespace std;
int l,maxl,q;
int i,n;
int a,b;
int main()
{
   freopen("input.txt", "rt", stdin);
   freopen("output.txt", "wt", stdout);
   cin >> n;
   cin >> a;
   if (n==1)
   {
      cout << 1;
      return 0;
   }
   cin >> b;
   i = 2;
   while (i<n && b==a)
   {
      cin >> b;
      i++;
   }
   if (b==a)
   {
      cout << 1;
      return 0;
   }
   l = 2;
   if (a>b)
      q = 1;
   else
      q = 0;
   for (;i<n;i++)
   {
      a = b;
      cin >> b;
      if (q==1)
      {
     if (a<b)
        l++;
     else
     {
        maxl = max(maxl,l);
        l = 2;
        q = 1-q;
        //cout << "smena " << b << endl;
     }
      }
      else
      {
     if (a>b)
        l++;
     else
     {
        maxl = max(maxl,l);
        //cout << "smena " << b << endl;
        l = 2;
        q = 1-q;

     }
      }
      q = 1 - q;
   }

   cout << max(maxl,l);
   return 0;
}
