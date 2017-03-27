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

int main() {
  string s;
  int i,m = 0,p;
  in >> s;
  for(i = 0; i < s.length(); i++) {
    p = 0;
    while (i < s.length() && s[i]=='0') {
      i++;
      p++;
    }
    if (p>m)
      m = p;
  }
  out << m;
  return 0;
}
