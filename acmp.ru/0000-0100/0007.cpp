#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
string s1,s2,s3;
int main()
{
   in >> s1 >> s2 >> s3;
   if (s1.length()>s2.length() || ( s1.length()==s2.length() && s1>s2) )
   {
      if (s1.length()>s3.length() || ( s1.length()==s3.length() && s1>s3))
     out << s1;
      else
     out << s3;
   }
   else if (s2.length()>s3.length() || ( s2.length()==s3.length() && s2>s3))
      out << s2;
   else
      out << s3;
   return 0;
}
