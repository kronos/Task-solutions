#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
const long long mod = 1000000007;
long long n, m, ans;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  ans = 0;
  if (abs(n-m) <= 1) {
    ans = 1;
    for (int i = 0; i < n; i++) {
      ans = (ans*(n-i)) % mod;
    }

    for (int i = 0; i < m; i++) {
      ans = (ans*(m-i)) % mod;
    }

    if (n == m) {
      ans = (ans*2) % mod;
    }
  }

  cout << ans;

  return 0;
}
