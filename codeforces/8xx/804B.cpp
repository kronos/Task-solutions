#include <iostream>
#include <string>

using namespace std;
unsigned long long mod = 1000000007;
unsigned long long ans, count_a;
string s;

unsigned long long modpow(unsigned long long exp) {
  if (exp == 0) {
    return 1;
  }

  unsigned long long p = modpow(exp/2);
  p = p*p % mod;
  return (exp % 2 == 0) ? p : (2 * p) % mod;
}

unsigned long long calc(unsigned long long num) {
  return 2*modpow(num-1) - 1;
}

int main() {
  cin >> s;
  int len = s.length();

  for (int i = 0; i < len; i++) {
    if (s[i] == 'a') {
      count_a++;
    } else if (count_a > 0) {
      ans = (ans + calc(count_a)) % mod;
    }
  }

  cout << ans << "\n";
  return 0;
}
