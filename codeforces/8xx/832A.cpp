#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

long long n,k;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  long long q = n / k;
  if (q % 2 == 1) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
