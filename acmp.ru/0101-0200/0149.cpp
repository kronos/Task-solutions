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
   int i,n,k;
   in >> n;
   for(i=0;i<n;i++)
   {
      in >> k;
      t.push_back(k);
   }
   reverse(t.begin(),t.end());
   for(i=0;i<n;i++)
      out << t[i] << " ";
   return 0;
}
