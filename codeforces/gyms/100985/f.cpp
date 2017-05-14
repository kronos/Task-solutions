#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>

using namespace std;
int n, m , k;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> n >> m >> k;

  int more = max(0, (int)ceil(0.7*n - k));
  if (more > (n-m)) {
    cout << "-1\n";
  } else {
    cout << more << "\n";
  }
  cout << floor((k+(n-m))/(double)n*100) << "\n";
  return 0;
}
