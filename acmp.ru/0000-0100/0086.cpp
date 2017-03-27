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
   int n;
   in >> n;
   if (n<3)
      out << "0";
   else
      out << n*n-3*n+2;
   return 0;
}
