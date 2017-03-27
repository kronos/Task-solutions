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
string s;
vector<string> t;
int main()
{
   int s,p,y1,y2,x1,x2;
   in >> s >> p;
   y1 = (s+sqrtf(s*s-4*p))/2;
   y2 = (s-sqrtf(s*s-4*p))/2;
   x1 = s-y1;
   x2 = s-y2;
   if (x1>0 && y1>0)
   {
      if (x1>y1)
     out << y1 << " " << x1;
      else
     out << x1 << " " << y1;
   }else
   {
      if (x2>y2)
     out << y2 << " " << x2;
      else
     out << x2 << " " << y2;
   }
   return 0;
}
