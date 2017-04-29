#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
int n;
unsigned digits(unsigned long long int n) {
    unsigned digits = 0;
    while (n) {
        n /= 10;
        digits++;
    }
    return digits;
}

unsigned long long int S(unsigned long long int n) {
  if (n == 0) {
    return 0;
  }

  unsigned long long int ans = 0, t = 1;
  unsigned l = digits(n);

  if (l > 1) {
    ans = 9;
    for (int i = 2; i < l; i++) {
      ans += 9*t;
      t *= 10;
    }
    t *= 10;
    int first = n / t;
    int last  = n % 10;
    ans += (first-1)*(t/10);

    if (first <= last) {
      ans += (n % t) / 10 + 1;
    } else {
      ans += (n % t) / 10;
    }
  } else {
    ans = n;
  }

  return ans;
}

int main() {
  unsigned long long int l,r;
  int t;
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    cin >> l >> r;
    cout << S(r) - S(l-1) << "\n";
  }
  return 0;
}
