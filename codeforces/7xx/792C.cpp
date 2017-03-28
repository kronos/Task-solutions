#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int n, end_zero;
string s;

bool found_first[10];
bool found_second[10];
int first[10];
int second[10];
vector<string> ans;

void add_one(const string& s, const int pos) {
  int i;
  string s1 = s.substr(0, pos) + s.substr(pos + 1, s.length() - pos - 1);

  for (i = 0; i < s1.length() && s1[i] == '0'; ++i)
  {}

  if (i < s1.length()) {
    ans.push_back(s1.substr(i, s1.length() - i));
  }
}

void add_two(const string& s, int a, int b) {
  int i;
  if (a > b) {
    int t = a;
    a = b;
    b = t;
  }
  string s1 = s.substr(0, a) + s.substr(a + 1, b - a - 1) + s.substr(b + 1, s.length() - b - 1);

  for (i = 0; i < s1.length() && s1[i] == '0'; ++i)
  {}

  if (i < s1.length()) {
    ans.push_back(s1.substr(i, s1.length() - i));
  }
}

int main() {
  cin >> s;
  int sum = 0;
  int i,n;

  for (i = s.length() - 1; i >= 0; i--) {
    n = s[i] - '0';

    if (found_second[n]) {
      if (!found_first[n]) {
        found_first[n] = true;
        first[n] = i;
      }
    } else {
      found_second[n] = true;
      second[n] = i;
    }
    sum += n;
  }

  int rem = sum % 3;

  if (rem == 0) {
    ans.push_back(s);
  } else if (rem == 1) {
    if (found_second[1]) {
      add_one(s, second[1]);
    }

    if (found_second[4]) {
      add_one(s, second[4]);
    }

    if (found_second[7]) {
      add_one(s, second[7]);
    }

    if (found_first[2] && found_second[2]) {
      add_two(s, first[2], second[2]);
    }

    if (found_first[5] && found_second[5]) {
      add_two(s, first[5], second[5]);
    }

    if (found_first[8] && found_second[8]) {
      add_two(s, first[8], second[8]);
    }

    if (found_second[2] && found_second[5]) {
      add_two(s, second[2], second[5]);
    }

    if (found_second[2] && found_second[8]) {
      add_two(s, second[2], second[8]);
    }
  } else if (rem == 2) {
    if (found_second[2]) {
      add_one(s, second[2]);
    }

    if (found_second[5]) {
      add_one(s, second[5]);
    }

    if (found_second[8]) {
      add_one(s, second[8]);
    }

    if (found_first[1] && found_second[1]) {
      add_two(s, second[1], first[1]);
    }

    if (found_first[4] && found_second[4]) {
      add_two(s, second[4], first[4]);
    }

    if (found_first[7] && found_second[7]) {
      add_two(s, second[7], first[7]);
    }

    if (found_second[1] && found_second[7]) {
      add_two(s, second[1], second[7]);
    }

    if (found_second[1] && found_second[4]) {
      add_two(s, second[1], second[4]);
    }

    if (found_second[4] && found_second[7]) {
      add_two(s, second[4], second[7]);
    }
  }

  if (ans.size() == 0) {
    if(found_second[0]) {
      cout << 0;
    } else {
      cout << -1;
    }
  } else {
    int ml = ans[0].length();
    int mi = 0;
    for (i = 1; i < ans.size(); i++) {
      if (ans[i].length() > ml) {
        ml = ans[i].length();
        mi = i;
      }
    }
    cout << ans[mi];
  }
  return 0;
}
