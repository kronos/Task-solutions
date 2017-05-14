#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
int n,mx,ans,x;
bool doubled;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> n;
  cin >> mx;
  ans = 1;
  for (int i = 1; i < n; i++) {
    cin >> x;
    if (x > mx) {
      doubled = false;
      mx = x;
      ans = i+1;
    } else if (x == mx) {
      doubled = true;
    }
  }

  if (doubled) {
    ans = -1;
  }
  cout << ans << "\n";
  return 0;
}
