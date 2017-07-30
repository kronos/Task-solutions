#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;
long long n,a,b;
long long h[100000];

bool check(int p) {
  int p_left = p;
  bool good = true;
  long long z = a - b, zz, need_a;
  for (int i = 0; (i < n) && good; i++) {
    if (h[i] > b*p) {
      zz = h[i] - p*b;

      need_a = zz / z;
      if (zz % z) {
        need_a++;
      }
      good = need_a <= p_left;
      p_left -= need_a;
    }
  }

  return good;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  priority_queue<int, vector<int> > heap;
  cin >> n >> a >> b;
  int x;
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }

  long long l = 0, r = 1000000001;
  long long mid;
  while (r-l > 1) {
    mid = (r + l) /2;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }

  cout << r << endl;
  return 0;
}
