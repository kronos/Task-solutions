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
int m[2];
int main()
{
   int i,n,j,r=0;
   in >> n;
   for(i=0;i<n;i++)
   {
      in >> j;
      m[j]++;
   }
   out << min(m[0],m[1]);
   return 0;
}
