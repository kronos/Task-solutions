#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;
int n;
long long a[50];
long long b[50];
long long ans;

bool check(long long k) {
  bool good = true;
  long long ans = 0,q;
  int imax;

  for (int i = 0; i < n; i++) {
    a[i] = b[i];
  }

  while (ans <= k) {
    imax = 0;
    for (int i = 1; i < n; i++) {
      if (a[i] > a[imax]) {
        imax = i;
      }
    }

    if (a[imax] < n) {
      break;
    }

    q = a[imax]/n;
    for (int i = 0; i < n; i++) {
      a[i] += q;
    }
    a[imax] -= q*(n+1);
    ans += q;
  }
  return ans <= k;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> n;
  long long mmax = 0;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    mmax = max(mmax, b[i]);
  }

  if (mmax >= n) {
    long long l = -1;
    long long r = 500000000000000001;
    long long mid;
    while (r - l > 1) {
      mid = (l+r)/2;
      if (check(mid)) {
        r = mid;
      } else {
        l = mid;
      }
    }
    ans = r;
  }
  cout << ans << "\n";
  return 0;
}
