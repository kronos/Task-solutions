#include <iostream>
#include <algorithm>

using namespace std;
const int limit = 1100;
int a[100001];
unsigned short cache[100001][limit];
int n, k;

int calc(int p) {
  if (p > n) {
    return 0;
  }

  if (k < limit) {
    if (cache[p][k] > 0) {
      return cache[p][k];
    } else {
      return cache[p][k] = 1 + calc(p + k + a[p]);
    }
  } else {
    return 1 + calc(p + k + a[p]);
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int q, p;
  int answer;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  cin >> q;

  for (int i = 0; i < q; i++) {
    cin >> p >> k;
    cout << calc(p) << "\n";
  }
  return 0;
}
