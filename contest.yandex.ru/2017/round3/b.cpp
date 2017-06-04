#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;
int n;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int x, y;
  string s;
  cin >> s >> x >> y;
  char xx = '0' + x;
  char yy = '0' + y;

  if (s.length() == 1) {
    if (s[0] >= yy) {
      s[0] = yy;
    } else if (s[0] >= xx && xx != '0') {
      s[0] = xx;
    } else {
      s = "-1";
    }
  } else {
    int q = 0;
    int last_yy = -1;

    while (q < s.length()) {
      if (s[q] != yy) {
        if (s[q] != xx) {
          break;
        }
      } else {
        last_yy = q;
      }
      q++;
    }

    if (q < s.length()) {
      if (s[q] < xx) {
        if (last_yy > -1 && (last_yy > 0 || xx > '0')) {
          s[last_yy] = xx;
          for (int i = last_yy + 1; i <= q; i++) {
            s[i] = yy;
          }
        } else {
          for (int i = 1; i <= q; i++) {
            s[i] = yy;
          }
          s[0] = ' ';
        }
      } else if (s[q] > xx && s[q] < yy) {
        if (xx == '0' && q == 0) {
          s[q] = ' ';
        } else {
          s[q] = xx;
        }
      } else {
        s[q] = yy;
      }

      for (int i = q + 1; i < s.length(); i++) {
        s[i] = yy;
      }
    }
  }

  cout << s;
  return 0;
}
