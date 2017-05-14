#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>

using namespace std;
int n;
unsigned ans;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> n;
  ans = log2(n) + 1;
  cout << ans << endl;
  return 0;
}
