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
   int i;
   s = "qwertyuiopasdfghjklzxcvbnmq";
   in >> c;  
   for (i=0;s[i]!=c;)
      i++;
   out << s[i+1];
   return 0;
}
