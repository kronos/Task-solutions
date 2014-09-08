#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <map>
using namespace std;
string s;
int a[255],i,r,p;
int main()
{

   r=0;
   getline(cin,s);
   p = 1;
   for(char i='a';i<='z';i++)
   {
      a[i] = p;
      p++;
      if (p==4)
   p = 1;
   }
   a[' '] = 1;
   a['.'] = 1;
   a[','] = 2;
   a['!'] = 3;
   for(i=0;i<s.length();i++)
      r+=a[s[i]];
   cout << r;
   return 0;
}
