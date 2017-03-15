#include <iostream>
#include <vector>
#include <string>

using namespace std;
int n, m, answer, i;
int minl1 = 1000000009, minr1 = 1000000009;
int minl2 = 1000000009, minr2 = 1000000009;

int maxl1, maxr1;
int maxl2, maxr2;
int x,y;
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x >> y;
    if (y < minr1) {
      minl1 = x;
      minr1 = y;
    }

    if (x > maxl1) {
      maxl1 = x;
      maxr1 = y;
    }
  }

  cin >> m;
  for (i = 0; i < m; i++) {
    cin >> x >> y;
    if (y < minr2) {
      minl2 = x;
      minr2 = y;
    }

    if (x > maxl2) {
      maxl2 = x;
      maxr2 = y;
    }
  }

  if (maxl2 > minr1) {
    answer = maxl2 - minr1;
  }

  if (maxl1 - minr2 > answer ) {
    answer = maxl1 - minr2;
  }

  cout << answer;
  return 0;
}
