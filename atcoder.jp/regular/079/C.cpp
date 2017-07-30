#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;
int n, m,x,y;

bool from_one[200001];
bool to_n[200001];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    if (x == 1) {
      from_one[y] = true;
    } else if (x == n) {
      to_n[y] = true;
    } else if (y == 1) {
      from_one[x] = true;
    } else if (y == n) {
      to_n[x] = true;
    }
  }

  bool good = false;
  for (int i = 1; (i <= n) && !good; i++) {
    good = from_one[i] && to_n[i];
  }
  if (good) {
    cout << "POSSIBLE";
  } else {
    cout << "IMPOSSIBLE";
  }
  return 0;
}
