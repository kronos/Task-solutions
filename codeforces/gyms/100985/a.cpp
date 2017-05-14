#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
int n;
long long a,b;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> n;
  while (n--) {
    cin >> a >> b;
    if (__gcd(a,b) > 1) {
      cout << "Sim\n";
    } else {
      cout << "Nao\n";
    }
  }
  return 0;
}
