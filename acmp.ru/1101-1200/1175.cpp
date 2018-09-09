#include <iostream>

using namespace std;

int n,q;
int table[19][100000];

int msb(int N) {
  return N ? 32 - __builtin_clz(N) : 0;
}

int min_value(int i, int j) {
  int len = msb(j-i + 1);
  return min(table[len][i], table[len][j + 1 - (1 << (len-1))]);
}

int main() {
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> table[1][i];
  }
  int p = 1, l, r, len = msb(n);
  for (int i = 2; i <= len; i++) {
    for (int j = 0; j < n-p; j++) {
      table[i][j] = min(table[i-1][j], table[i-1][j+p]);
    }
    p <<= 1;
  }

  cin >> q;

  while (q--) {
    cin >> l >> r;
    cout << min_value(l-1, r-1) << " ";
  }
  return 0;
}
