#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
int n, i;
string s;

string d = "abba";
int main() {
  cin >> n;

  for (; i < n-4; i+= 4) {
    s += d;
  }

  for (; i < n; i++) {
    s += d[i % 4];
  }

  cout << s << "\n";

  return 0;
}
