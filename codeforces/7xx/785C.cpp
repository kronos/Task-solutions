#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
signed long long n, m, answer;

signed long long calc(signed long long n, signed long long m) {
  signed long long answer;
  if (m - n >= 1) {
    answer = n;
  } else {
    answer = m + (signed long long)ceil((sqrt(1.0L + 8.0L*(n - m)) - 1.0L)/2.0L);
  }
  return answer;
}

int main() {
  cin >> n >> m;
  cout << calc(n,m);
  return 0;
}
