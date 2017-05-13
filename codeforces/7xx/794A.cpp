#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
int a,b,c,x,n;
unsigned long long ans;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> a >> b >> c >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x > b && x < c) {
      ans++;
    }
  }
  cout << ans << "\n";
  return 0;
}
