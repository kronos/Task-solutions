#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;

long long a[100000];
int n;

bool check(long long len) {
  if (len < 2) {
    return true;
  }

  bool good = false;

  for (int i = len-1; (i <= n-len) && !good;) {
    if (a[i] >= len) {
      good = true;
      int j = 1;
      for (; (j < len) && good;) {
        good = (a[i-j] >= (len - j)) && (a[i+j] >= (len - j));
        if (good) {
          j++;
        }
      }

      if (!good) {
        if (a[i+j] < (len - j)) {
          i = i+j + (len - a[i+j]);
        } else {
          i = i-j + (len - a[i-j]);
        }
      }
    } else {
      i += len-a[i];
    }
  }

  return good;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  long long ans, p, z, sum, len, maxa;
  bool found;
  while (t--) {
    cin >> n;
    cin >> a[0];
    sum = a[0];
    maxa = 0;
    for (int i = 1; i < n; i++) {
      cin >> a[i];
      sum += a[i];
      if (a[i] > maxa) {
        maxa = a[i];
      }
    }

    long long l = 0;
    long long r = min(maxa, (long long)(n+1)/2) + 1;
    long long mid;

    while (r-l > 1) {
      mid = (r+l)/2;
      if (check(mid)) {
        l = mid;
      } else {
        r = mid;
      }
    }
    cout << sum - l*l << "\n";
  }
  return 0;
}
