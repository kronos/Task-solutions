#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

int len, q;
string s;
int occ[27];
int ans[27][1501];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> len >> s >> q;
  int m, replace_count;
  char c, ccc;

  for (int i = 0; i < s.length(); i++) {
    occ[s[i]-'a']++;
  }

  for (int i = 0; i < 27; i++) {
    ccc = 'a' + i;
    if (occ[i] > 0) {
      for (int j = 0; j < len; j++) {
        replace_count = 0;
        for (int k = j; k < len; k++) {
          if (s[k] != ccc) {
            replace_count++;
          }
          ans[i][replace_count] = max(ans[i][replace_count], k-j+1);
        }
      }

      for (int j = 1; j < len; j++) {
        ans[i][j] = max(ans[i][j], ans[i][j-1]);
      }
    }
  }

  while (q--) {
    cin >> m >> c;
    if (occ[c-'a']) {
      if (m >= len - occ[c-'a']) {
        cout << len << "\n";
      } else {
        cout << ans[c-'a'][m] << "\n";
      }
    } else {
      cout << m << "\n";
    }
  }
  return 0;
}
