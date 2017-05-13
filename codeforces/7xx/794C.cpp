#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
string s1;
string s2;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> s1 >> s2;
  int n = s1.length();
  string ans(n, '?');
  if (n == 1) {
    ans = s1;
  } else {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    int olegl = 0;
    int olegr = n/2 - (1 - n%2);
    int igorl = n-olegr - (1 - n%2);
    int igorr = n-1;
    int l = 0;
    int r = n-1;
    int left;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        if (s1[olegl] < s2[igorr]) {
          ans[l++] = s1[olegl++];
        } else {
          left =
          ans[r--] = s1[olegr--];
        }
      } else {
        if (s2[igorr] > s1[olegl]) {
          ans[l++] = s2[igorr--];
        } else {
          ans[r--] = s2[igorl++];
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
