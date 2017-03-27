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
  int i,n,p,c=0;
  string s = "2.7182818284590452353602875";
  in >> n;
  if (n==0) {
     out << "3";
  } else {
    if (n==25) {
      out << s;
    } else {
      if (s[n+2] > '4') {
        s[n+1]++;
      }
      out << s.substr(0, n + 2);
    }
  }
  return 0;
}
