#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
int n;
unsigned long long b,m,ans;

unsigned long long cnt(unsigned long long x, unsigned long long y) {
  unsigned long long a;
  a = (1+x)*x/2;
  return (y+1)*a + (x+1 + (x+1)*y)*y/2;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  unsigned long long x,y,z;
  cin >> m >> b;

  for (unsigned long long y = 0; y <= b; y++) {
    x = (b-y)*m;
    z = cnt(x,y);

    if (z > ans) {
      ans = z;
    }
  }
  cout << ans;
  return 0;
}
