#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;
int main()
{
   int n;
   cin >> n;
   int c = 1,x,y;
   cin >> x;
   n--;
   while (n--)
   {
      cin >> y;
      if (x==y)
   c++;
      else
      {
   cout << c << " " << x << " ";
   x = y;
   c = 1;
      }
   }
   if (c)
      cout << c << " " << x << " ";
   return 0;
}
