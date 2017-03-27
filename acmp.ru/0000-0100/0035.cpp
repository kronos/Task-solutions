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
   int i,n,m,c=0,k;
   in >> k;
   unsigned long long int r;
   for(i=0;i<k;i++)
   {
      in >> n >> m;
      r = (n + 239)*(n + 366)/2;
      r+= 19*m;
      out << r << endl;
   }
   return 0;
}
