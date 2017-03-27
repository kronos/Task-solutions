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
   unsigned int i,m=0,p;
   in >> p;
   while (p)
   {
      if (p%2)
     m++;
      p/=2;
   }
   out << m;
   return 0;
}
