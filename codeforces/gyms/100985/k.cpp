#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
string s;
int n;
char c;
stringstream ss;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> s;
  for (int i = 0; i < s.length(); ) {
    if (i < s.length()-1 && s[i] == s[i+1]) {
      c = s[i];
      n = 2;
      i += 2;
      while (i < s.length() && s[i] == c) {
        n++;
        i++;
      }
      ss << c << n;
    } else {
      ss << s[i] << '1';
      i++;
    }
  }
  cout << ss.str() << "\n";
  return 0;
}
