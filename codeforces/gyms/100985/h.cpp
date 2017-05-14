#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
int n;
unsigned long long ans;
long long fl[1000000]; // 10^6
long long foot[1000000]; // 10^6
long long chain[1000000]; // 10^6
unsigned long long d1,d2;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> fl[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> foot[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> chain[i];
  }

  for (int i = 0; i < n; i++) {
    d1 += (fl[i] - foot[i]) * (fl[i] - foot[i]);
    d2 += (fl[i] - chain[i]) * (fl[i] - chain[i]);
  }

  if (d1 <= d2) {
    cout << "Yan\n";
  } else {
    cout << "MaratonIME\n";
  }
  return 0;
}
