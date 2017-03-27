//#include <iostream>
//#include <math.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <sstream>

using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
string s,r;
const int N = 1999;

int main()
{
   string s;
   in >> s;
   int i;
   if (s.length()<2)
      out << s << " 0";
   else
   {
      int r=0,p,n=1;
      for(i=0;i<s.length();i++)
     r+=s[i]-'0';
      while (r>=10)
      {
     n++;
     p = 0;
     while (r>0)
     {
        p+=r%10;
        r/=10;
     }
     r = p;
      }
      out << r << " " << n;
   }
   return 0;
}
