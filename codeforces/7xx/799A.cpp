#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

int n, t, k, d;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n >> t >> k >> d;
  int cnt = n/k;

  if (n%k) {
    cnt++;
  }

  if (t * cnt > d + t) {
    cout << "YES";
  } else {
    cout << "NO";
  }

  return 0;
}
