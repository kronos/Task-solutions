#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
long long p;
using namespace std;

bool f(long long s) {
  long long i = (s / 50) % 475;
  long long n = 25;
  while (n--) {
    i = (i * 96 + 42) % 475;
    if (p == 26 + i) {
      return true;
    }
  }

  return false;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  long long x,y,q;
  cin >> p >> x >> y;
  q = x;
  long long ans = 0;
  x += 50;
  do {
    x -= 50;
  } while (x - y >= 50 && !f(x));
  if (!f(x)) {
    x = q+50;
    long long d = 1;
    ans++;
    while (!f(x)) {
      x+=50;
      d++;
      if (d%2) {
        ans++;
      }
    }
  }
  cout << ans;
  return 0;
}
