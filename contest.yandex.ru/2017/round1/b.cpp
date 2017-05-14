#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
int n;
unsigned long long ans;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  long long n,a, ans,to,f,t;
  cin >> n >> a;
  ans = 0;
  a = a % 10000;
  n = n % 10000;

  if (a <= n-a) {
    f = a;
    t = n-a;
  } else {
    f = n-a;
    t = a;
  }

  for (long long i = f; i <= t; i+= 1) {
    ans = max(ans, (5000 - (i % 5000)) % 500 + (5000 - (n-i) % 5000) % 500);
  }
  cout << ans << "\n";
  return 0;
}
