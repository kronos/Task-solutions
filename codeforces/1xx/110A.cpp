#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool check(const string& s) {
  int len = s.length(), n = 0, i;
  for (i = 0; i< len; ++i) {
    if (s[i] == '4' || s[i] == '7') {
      n++;
    }
  }
  stringstream ss;
  ss << n;
  string s2 = ss.str();
  len = s2.length();

  for (i=0; i < len; ++i) {
    if (s2[i] != '4' && s2[i] != '7') {
      return false;
    }
  }
  return true;
}

int main() {
  string s;
  cin >> s;
  if (check(s))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
