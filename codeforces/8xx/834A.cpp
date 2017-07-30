#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;
int n;
string s;
map<char, string> cw;
map<char, string> ccw;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cw['^'] = "^>v<^";
  cw['>'] = ">v<^>";
  cw['v'] = "v<^>v";
  cw['<'] = "<^>v<";

  ccw['^'] = "^<v>^";
  ccw['>'] = ">^<v>";
  ccw['v'] = "v>^<v";
  ccw['<'] = "<v>^<";
  char c,c2;

  cin >> c >> c2;
  s = c; s+= c2;
  cin >> n;
  n = n % 4;

  if (cw[s[0]][n] == ccw[s[0]][n]) {
    cout << "undefined";
  } else if (cw[s[0]][n] == s[1]) {
    cout << "cw";
  } else if (ccw[s[0]][n] == s[1]) {
    cout << "ccw";
  } else {
    cout << "ERROR";
  }

  return 0;
}
