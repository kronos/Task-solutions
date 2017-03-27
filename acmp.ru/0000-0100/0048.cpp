#include <cmath>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
string s,p;
int i;
int main() {
   in >> s;
   p = "";
   for(i=s.length()-1;i>0;i--) {
      if (s[i]!='0')
         break;
      p += '0';
   }

   out << "1" << p;

   return 0;
}
