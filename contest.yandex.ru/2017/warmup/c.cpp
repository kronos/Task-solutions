#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
int n, k;
int a[2001];
bool f[2001];
int ans;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> k;
    a[k+1000]++;
  }
  bool curry = false;
  int p = 0;
  for (int i = 0; i <= 2000; i++) {
    if (a[i] > 0) {
      ans += a[i] / 2;
      if (a[i] % 2 != 0) {
        if (curry) {
          curry = false;
        } else {
          ans++;
          curry = true;
          p = 0;
        }
      }
    } else {
      p++;
      if (p == 2) {
        curry = false;
      }
    }
  }
  cout << ans;
  return 0;
}
