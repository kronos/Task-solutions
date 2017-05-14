#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;
int n,m,coins,max_coins;
vector<string> mmap(1000);
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> mmap[i];
  }

  coins = max_coins = 0;
  for (int i = 0; i < n; i++) {
    if (i%2) {
      for (int j = m-1; j >= 0; j--) {
        if (mmap[i][j] == '.') {
          coins++;
        } else if (mmap[i][j] == 'L') {
          max_coins = max(max_coins, coins);
          coins = 0;
        }
      }
    } else {
      for (int j = 0; j < m; j++) {
        if (mmap[i][j] == '.') {
          coins++;
        } else if (mmap[i][j] == 'L') {
          max_coins = max(max_coins, coins);
          coins = 0;
        }
      }
    }
  }
  cout << max_coins << "\n";
  return 0;
}
