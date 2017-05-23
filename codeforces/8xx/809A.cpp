#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
const int mod = 1000000007;

int n;
long long ans,p,q,pp;
long long a[300000];
long long sum[300000];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);

  sum[0] = a[0];
  for (int i = 1; i < n; i++) {
    sum[i] += sum[i-1] + a[i];
  }
  p = 1;
  for (int j = 1; j < n; j++) {
    q = (((sum[n-1] - sum[j-1] - sum[n-1-j]) % mod) * p) % mod;
    ans = (ans + q) % mod;
    p = (p * 2) % mod;
  }

  cout << ans << "\n";
  return 0;
}
