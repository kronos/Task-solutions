#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
int n;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> n;
  for (int i = 2; ;i++) {
    if (n%i > 0) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
