#include <iostream>

using namespace std;

int main() {
  int a, b;
  cin >> a;
  int ans = 0;
  while (a > 1) {
    if (a & 1) {
      a++;
    } else {
      a/=2;
    }
    ans++;
  }
  cout << ans << endl;
    return 0;
}
