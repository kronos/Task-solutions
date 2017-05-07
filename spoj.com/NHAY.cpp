#include <iostream>
#include <vector>
#include <string>

using namespace std;
int pi[2000001];
int temp;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  string p, t, x;

  while (cin >> temp) {
    vector<int> a;
    cin >> p >> t;
    x = p + "@" + t;
    int len = p.length(), j;
    pi[0] = 0;
    for (int i = 1; i < x.length(); i++) {
      j = pi[i-1];
      while (j > 0 && x[i] != x[j]) {
        j = pi[j-1];
      }

      if (x[i] == x[j]) {
        j++;
      }
      pi[i] = j;
      if (j == len && i > len) {
        a.push_back(i-2*len);
      }
    }

    for (int i = 0; i < a.size(); i++) {
      cout << a[i] << "\n";
    }

    if (a.size() == 0) {
      cout << "\n";
    }
  }
  return 0;
}
