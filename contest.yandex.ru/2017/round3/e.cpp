#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int x1, y1, x2, y2, ans;
  cin >> x1 >> y1 >> x2 >> y2;
  x1 += 100;
  x2 += 100;
  y1 += 100;
  y2 += 100;

  int min_d = min(abs(x1-x2), abs(y1-y2));
  int max_d = max(abs(x1-x2), abs(y1-y2));
  int q = max_d - min_d;

  if (q < 2) {
    ans = (abs(x1-x2) + abs(y1-y2));
  } else {
    ans = min_d*2 + (q/2)*3+(q-q/2);
  }

  cout << ans << '\n';

  return 0;
}
