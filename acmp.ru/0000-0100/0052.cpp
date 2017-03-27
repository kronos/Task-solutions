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
   int x,i,s1=0,s2=0,r;
   in >> s;
   stringstream ss;
   ss << s;
   ss >> x;
   r = s.length();
   for(i=0;i<r/2;i++)
   {
      s1+=x%10;
      x/=10;
   }
   if (r%2!=0)
      x/=10;
   for(;x;)
   {
      s2+=x%10;
      x/=10;
   }

   if (s1==s2)
      out << "YES";
   else
      out << "NO";
   return 0;
}
