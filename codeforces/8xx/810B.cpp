#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
int n,f;
unsigned long long ans;
int d[100000];

int main() {
  int l, k;
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> n >> f;
  for (int i = 0; i < n; i++) {
    cin >> k >> l;
    ans += min(k, l);
    if (l > k) {
      d[i] = min(k, l-k);
    } else {
      d[i] = 0;
    }
  }
  sort(d, d+n);
  for (int i = 1; i <= f; i++) {
    ans += d[n-i];
  }
  cout << ans << "\n";
  return 0;
}
