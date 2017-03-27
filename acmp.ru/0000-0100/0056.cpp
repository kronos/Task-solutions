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
map<string,bool> fr,mfr,afr;
map<string,bool>::iterator it;
int main()
{
   int i,n,j,r=0;
   in >> n;
   for(i=0;i<n;i++)
   {
      in >> s;
     // t.push_back(s);
      fr[s] = true;
   }
   in >> n;
   for(i=0;i<n;i++)
   {
      in >> s;
      if (fr.find(s)!=fr.end())
     mfr[s] = true;
      else
     afr[s] = true;
   }
   out << "Friends: ";
   bool first = true;
   for(it = fr.begin();it!=fr.end();it++)
   {
      if (first)
     first = false;
      else
     out << ", ";
      out << it->first;
   }
   out << endl;

   out << "Mutual Friends: ";
   first = true;
   for(it = mfr.begin();it!=mfr.end();it++)
   {
      if (first)
     first = false;
      else
     out << ", ";
      out << it->first;
   }
   out << endl;

   out << "Also Friend of: ";
   first = true;
   for(it = afr.begin();it!=afr.end();it++)
   {
      if (first)
     first = false;
      else
     out << ", ";
      out << it->first;
   }
   out << endl;

   return 0;
}
