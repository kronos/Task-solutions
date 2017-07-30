#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

const long long mod = 1000000007;
long long t, l, r, ans;

long long d[5000001];
long long f[5000001];
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> t >> l >> r;
  long long q = 1;
  int to = sqrt(r);

  for (int i = 2; i <= to; i++) {
    if (d[i] == 0) {
      for (int j = i*i; j <= r; j += i) {
        if (d[j] == 0) {
          d[j] = i;
        }
      }
    }
  }

  for (long long i = 2; i <= r; i++) {
    if (d[i]) {
      f[i] = (i/d[i] * f[d[i]] + f[i/d[i]]) % mod;
    } else {
      f[i] = i*(i-1)/2 % mod;
    }
  }

  for (long long i = l; i <= r; i++) {
    ans = (ans + q*f[i]) % mod;
    q = q*t % mod;
  }
  cout << ans;
  return 0;
}
