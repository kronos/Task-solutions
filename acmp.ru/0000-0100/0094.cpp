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
   int n,m,k;
   in >> n >> m >> k;
   if (n>=m)
   {
      out << "1";
   }
   else if (k>=n)
      out << "NO";
   else
   {
     if ((m-n)%(n-k)==0)
      out << 1+(m-n)/(n-k);
     else
      out << 2+(m-n)/(n-k);
   }

   return 0;
}
