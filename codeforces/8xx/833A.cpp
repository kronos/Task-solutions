#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;
int n;
long long sqrt3(long long a) {
  long long l = 0;
  long long r = 1000001;
  long long mid;
  while (r-l > 1) {
    mid = (r+l)/2;
    if (mid * mid * mid <= a) {
      l = mid;
    } else {
      r = mid;
    }
  }

  return l;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  long long a,b,z,q;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    q = a * b; // => x^3*y^3
    z = __gcd(a,b);
    long long c = sqrt3(q);
    if (c*c*c == q && (a/c)*(b/c) == c) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  return 0;
}

