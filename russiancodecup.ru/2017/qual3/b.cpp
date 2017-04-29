#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

struct character {
  int h, a;
};

character chars[100000];

bool comparator(const character& left, const character& right) {
  return left.a > right.a;
}

int main() {
  int n, H, A, a, t, ans;
  unsigned long long int sum;

  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> t;
  while (t--) {
    cin >> n >> H >> A;
    sum = 0;
    for (int j = 0; j < n; j++) {
      cin >> chars[j].h >> a;
      chars[j].a = (chars[j].h / A) * a;
      if ((chars[j].h % A) != 0) {
        chars[j].a += a;
      }
      sum += chars[j].a;
    }

    if (sum < H) {
      cout << -1 << "\n";
    } else {
      sort(chars, chars + n, comparator);
      ans = -1;
      while (H > 0) {
        ans++;
        H -= chars[ans].a;
      }
      cout << ans << "\n";
    }
  }

  return 0;
}
