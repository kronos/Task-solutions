//#include <iostream>
//#include <math.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <map>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
string s;
vector<int> t;
int main()
{
   int x,i,r=1;
   in >> x;
   if (x==0)
      out << "0";
   else
   {
      for(i=2;i<=x/2;i++)
     if (x%i==0)
        r+=i;
      out << r+x;
   }
   return 0;
}
