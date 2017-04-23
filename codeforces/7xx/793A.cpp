#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
unsigned long long int n, k;
int a[100000];
unsigned long long int x;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> n >> k;
  int m = 1e9+1;
  bool good = true;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    m = min(a[i], m);
  }
  for (int i = 0; (i < n) && good; i++) {
    if ((a[i] - m) % k != 0) {
      good = false;
    } else {
      x += a[i] - m;
    }
  }

  if (good) {
      cout << x / k;
  } else {
    cout << -1;
  }
  return 0;
}
