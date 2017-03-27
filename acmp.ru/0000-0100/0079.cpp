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
   int s,p,a,b,i;
   in >> a >> b;
   p = a%10;
   for(i=1;i<b;i++)
   {
      p = (p*a)%10;
   }
   out << p;
   return 0;
}
