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
   char c;
   int i,n,mi=30000,ma=0,x;
   in >> n;
   for (i=0;i<n;i++)
   {
      in >> x;
      if (x<mi)
     mi = x;
      if (x>ma)
     ma = x;
   }
   out << mi << " " << ma;
   return 0;
}
