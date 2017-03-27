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
   int i,x,y,a=0,b=0;
   for(i=0;i<4;i++)
   {
      in >> x >> y;
      a+=x;b+=y;
   }
   if (a==b)
      out << "DRAW";
   else if (a>b)
      out << "1";
   else
      out << "2";
   return 0;
}
