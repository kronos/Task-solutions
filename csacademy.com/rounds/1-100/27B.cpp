#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;
int n, x, pprev, a_cnt, b_cnt;
long long a[100000];
long long b[100000];

long long ans, sum, min_sum;
int main() {
    cin >> n;
    cin >> pprev;
    for (int i = 1; i < n; i++) {
      cin >> x;
      if (i % 2 == 1) {
        a[a_cnt++] = pprev + x;
      } else {
        b[b_cnt++] = pprev + x;
      }
      pprev = x;
    }

    min_sum = sum = ans = a[0];

    for (int r = 0; r < a_cnt; ++r) {
      sum += a[r];
      ans = max(ans, sum - min_sum);
      min_sum = min(min_sum, sum);
    }

    min_sum = sum = b[0];    b[0];

    for (int r = 0; r < b_cnt; ++r) {
      sum += b[r];
      ans = max(ans, sum - min_sum);
      min_sum = min(min_sum, sum);
    }

    cout << ans << endl;

    return 0;
}
