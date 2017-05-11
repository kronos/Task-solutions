#include <iostream>

using namespace std;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n,m,k,t,l;
  cin >> n >> m >> k;
  while (m--) {
    cin >> t >> l;
    if (t == 0) {
      if (l >= k) {
        k = l-k+1;
      }
    } else {
      if (n-l + 1 <=k) {
        k = n-l+n-k+1;
      }
    }
  }
  cout << k << endl;
  return 0;
}
