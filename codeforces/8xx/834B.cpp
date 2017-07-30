#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;
int n, k;
string s;
bool bad;
int first[26];
int last[26];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  cin >> s;
  int p;

  for (int i = 0; i < 26; i++) {
    first[i] = 1000001;
  }

  for (int i = 0; i < n; i++) {
    first[s[i]-'A'] = min(first[s[i]-'A'], i);
    last[s[i]-'A'] = i;
  }

  for (int i = 0; (i < n) && !bad; i++) {
    p = 0;
    for (int j = 0; j < 26; j++) {
      if (first[j] <= i && last[j] >= i) {
        p++;
      }
    }
    bad = p > k;
  }

  if (bad) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
