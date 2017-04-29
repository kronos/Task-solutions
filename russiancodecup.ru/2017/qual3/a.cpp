#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
  int n;
  unsigned k, m;
  string s;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> k;
    s = "";
    while (k > 0) {
        m = (k-1) % 26;
        s += 'A' + m;
        k = (k-m) / 26;
    }

    for (int j = 0; j < s.length() / 2; j++) {
        swap(s[j], s[s.length()-1-j]);
    }

    cout << s << "\n";
  }
  return 0;
}
