#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

string g,s,t;
bool good[27];

bool check(const string& s) {
  if (s.length() < t.length() - 1) {
    return false;
  }

  int from = -1;
  int len = min(t.length(), s.length());
  for (int i = 0; i < len; i++) {
    if (t[i] == '?') {
      if (!good[s[i]-'a']) {
        return false;
      }
    } else if (t[i] == '*') {
      from = i;
      break;
    } else {
      if (t[i] != s[i]) {
        return false;
      }
    }
  }

  if (from >= 0) {
    int to = s.length() - 1;
    int ti = t.length() - 1;
    while (t[ti] != '*') {
      if (t[ti] == '?') {
        if (!good[s[to]-'a']) {
          return false;
        }
      } else if (t[ti] == '*') {
        break;
      } else {
        if (t[ti] != s[to]) {
          return false;
        }
      }
      ti--;
      to--;
    }
    for (int i = from; i <= to; i++) {
      if (good[s[i]-'a']) {
        return false;
      }
    }
  } else {
    if (t.length() == s.length()) {
      return true;
    }

    if ((t.length() == s.length() + 1) && t[t.length()-1] == '*') {
      return true;
    } else {
      return false;
    }
  }

  return true;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> g >> t;
  for (int i = 0; i < g.length(); i++) {
    good[g[i] - 'a'] = true;
  }
  int n;
  cin >> n;
  while (n--) {
    cin >> s;
    if (check(s)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
