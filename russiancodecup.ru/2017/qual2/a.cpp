#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int t, n, m;

int a[20][20];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  int cnt = 0;
  int line = n-1;
  int column = 0;
  int p, cline, ccolumn;

  while(t--) {
    cin >> n >> m;
    line = 0;
    column = 0;
    ccolumn = 0;
    cline = 0;
    p = n*m;
    while (p > 0) {
      a[cline][ccolumn] = p;
      p--;
      ccolumn++;
      cline--;
      if (cline < 0) {
        line++;
        if (line > n-1) {
          line = n-1;
          column++;
        }
        ccolumn = column;
        cline = line;
      }

      if (ccolumn > m-1) {
        line++;
        if (line > n-1) {
          line = n-1;
          column++;
        }
        ccolumn = column;
        cline = line;
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << a[i][j] << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}
