#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int a, b;
long long n, len;
vector<int> x(100000);

long long check(long long l) {
  long long ans = 0;

  for (int i = 0; i < n; i++) {
    if (x[i] < l) {
      ans += l - x[i];
    } else if (x[i] > l) {
      ans += x[i] - l;
    }
    l += len;
  }

  return ans;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;

  while (t--) {
    cin >> n >> len >> a >> b;
    for (int i = 0; i < n; i++) {
      cin >> x[i];
    }
    sort(x.begin(), x.begin() + n);

    long long ans = 0;
    long long holes = (b-a) - len*n;

    if (holes > 0) {
      long long mid;
      long long l = a - 1;
      long long r = a + holes + 1;

      while (r - l > 1) {
        mid = (r+l) / 2;
        if (check(mid) < check(mid+1)) {
          r = mid;
        } else {
          l = mid;
        }
      }
      ans = check(mid);
    } else {
      ans = check(a);
    }

    cout << ans << '\n';
  }

  return 0;
}
