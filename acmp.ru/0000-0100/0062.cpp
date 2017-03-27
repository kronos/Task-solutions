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
   int i,j;
   in >> s;
   i = (s[0]-'A')%2;
   j = (s[1]-'1')%2;
   if (i==j)
      out << "BLACK";
   else
      out << "WHITE";
   return 0;
}
