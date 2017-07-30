#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
int n;
unsigned long long ans;
int a[50][50];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  bool rgood = true;
  for (int i = 0; (i < n) && rgood; i++) {
    for (int j = 0; (j < n) && rgood ; j++) {
      if (a[i][j] != 1) {
        bool good = false;
        for (int ii = 0; (ii < n) && !good; ii++) {
          for (int jj = 0; (jj < n) && !good; jj++) {
            good = a[ii][j] + a[i][jj] == a[i][j];
          }
        }

        if (!good) {
          rgood = false;
        }
      }
    }
  }
  if (rgood) {
    cout << "Yes";
  } else {
    cout << "No";
  }

  return 0;
}
