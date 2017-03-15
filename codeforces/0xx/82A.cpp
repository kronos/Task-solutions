#include <iostream>

using namespace std;

const char* answers[] = {
    "Sheldon",
    "Leonard",
    "Penny",
    "Rajesh",
    "Howard"
};

int main() {
  unsigned long long n, j, p;

  cin >> n;
  p = j = 1;

  while (j+5*p <= n) {
    j += 5*p;
    p <<= 1LL;
  }

  cout << answers[(n-j)/p] << endl;

  return 0;
}
