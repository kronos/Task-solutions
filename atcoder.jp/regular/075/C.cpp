#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;
int n;
unsigned long long ans;
int a[100];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> n;
  int k = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[k];
    ans += a[k];
    if (a[k] % 10) {
      k++;
    }
  }

  if (ans % 10) {
    cout << ans << endl;
  } else if (k > 0){
    sort(a, a+k);
    cout << ans - a[0] << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}
