#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int i,n,x;
int a[200000];

int main() {
  cin >> n;
  set<int> socks;
  int current = 0;
  int maximum = 0;
  for (i = 0; i < 2*n; i++) {
    cin >> x;
    if (socks.find(x) != socks.end()) {
      current--;
    } else {
      socks.insert(x);
      current++;
      if (current > maximum) {
        maximum = current;
      }
    }
  }
  cout << maximum << endl;
  return 0;
}
