#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <map>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
string s;
vector<int> t;
int main()
{
   int x,y,s;
   in >> x >> y;
   s = x+y-1;
   if (s<0)
      s = 0;
   out << s-x << " " << s-y;
   return 0;
}
