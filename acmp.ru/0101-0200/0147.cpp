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
vector<int> t;
int main()
{
   int i,n,f1=0,f2=1,t;
   in >> n;
   if (n==0)
      out << "0";
   else
   {
      for(i=1;i<n;i++)
      {
     t = f1;
     f1 = f2;
     f2+=t;
      }
      out << f2;
   }
   return 0;
}
