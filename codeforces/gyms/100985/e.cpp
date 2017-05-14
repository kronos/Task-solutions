#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
int n,m,l,r;
long long a[100001]; // 10^5

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  cin >> a[1];
  for (int i = 2; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i-1];
  }
  for (int i = 0; i < m; i++) {
    cin >> l >> r;
    if ((a[r] - a[l-1]) % 2 == 0) {
      cout << "Sim\n";
    } else {
      cout << "Nao\n";
    }
  }
  return 0;
}
