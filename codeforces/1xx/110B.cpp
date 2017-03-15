#include <iostream>
#include <string>

using namespace std;

const string s = "abcd";

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cout << s[i%4];
  }

  cout << endl;
  return 0;
}
