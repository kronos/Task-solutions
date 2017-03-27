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
   int x;
   for (int i=0;i<3;i++)
   {
      in >> x;
      t.push_back(x);
   }
   sort(t.begin(),t.end());
   out << t[2]-t[0];
   return 0;
}
