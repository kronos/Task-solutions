#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>

using namespace std;
int n;
long long x[1001];
long long y[1001];
long long r[1001];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i] >> r[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i+1; j <= n; j++) {
      if (((x[i]-x[j]) * (x[i]-x[j]) + (y[i]-y[j]) * (y[i]-y[j])) == (r[i] + r[j]) * (r[i] + r[j])) {
        cout << i << " " << j << "\n";
      }
    }
  }

  return 0;
}
