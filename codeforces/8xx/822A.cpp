#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

long long a, b;
int main() {
  cin >> a >> b;
  long long q = min(a,b);
  long long ans = 1;
  for (int i = 2; i <= q; i++) {
    ans *= i;
  }
  cout << ans;
  return 0;
}
