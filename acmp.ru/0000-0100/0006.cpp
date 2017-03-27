#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
string s;
int main()
{
   in >> s;
   if (s.length()!=5)
      out << "ERROR";
   else
   {
      if (s[0]<'A' || s[0]>'H' || s[3]<'A' || s[3]>'H' || s[1]<'1' || s[1]>'8' || s[4]<'1' || s[4]>'8' || s[2]!='-')
     out << "ERROR";
      else
      {
     int fx,fy,tx,ty;
     fx = s[0]-'A'+1;
     fy = s[1]-'0';
     tx = s[3]-'A'+1;
     ty = s[4]-'0';
     if ((labs(fx-tx)==1 && labs(fy-ty)==2) || (labs(fx-tx)==2 && labs(fy-ty)==1))
        out << "YES";
     else
        out << "NO";
      }
   }
   return 0;
}
