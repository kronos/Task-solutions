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
   int n,imax=-1,i,j,p,mmax = 0;
   in >> n;
   for(i=0;i<n;i++)
   {
      in >> j >> p;
      if (p==1 && j>mmax)
      {
     mmax = j;
     imax = i+1;
      }
   }
   out << imax;
   return 0;
}
