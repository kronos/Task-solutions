#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

int a, b, l, r;

size_t simulate_a(int l, int r) {
  bool taken[30];
  string s = "";
  char c;
  for (int i = 0; i < 30; i++) {
    taken[i] = false;
  }

  // initial string
  for (int i = 0; i < a; i++) {
    taken[i] = true;
    c = 'a' + i;
    s += c;
  }

  // B move
  for (int i = 0; i < b; i++) {
    taken[i] = false;
    taken[c - 'a'] = true;
    s += c;
  }


  size_t count = 0;

  // first comp move
  for (int i = 0; count < a;i++) {
    if (!taken[i]) {
      c = 'a' + i;
      s += c;
      count++;
    }
  }

  // B move
  for (int i = 0; i < b; i++) {
    s += c;
  }

  for (int i = 0; i < 30; i++) {
    taken[i] = false;
  }
  int mmax = 0;
  for (int i = 0; i < s.length(); i++) {
    if (!taken[s[i]-'a']) {
      taken[s[i]-'a'] = true;
      mmax++;
    }
  }
  for (int i = 0; i < 30; i++) {
    taken[i] = false;
  }

  int len = s.length();
  int k_l = l/len;
  r -= k_l*len;
  l -= k_l*len;
  if (l == 0) {
    r += len;
    l += len;
  }

  count = 0;
  l--; r--;
  s += s;
  s += s;

  for (int i = l; (i <= r) && (count < mmax); i++) {
    if (!taken[s[i]-'a']) {
      taken[s[i]-'a'] = true;
      count++;
    }
  }

  return count;
}

size_t simulate_b(int l, int r) {
  bool taken[30];
  string s = "";
  char c;
  for (int i = 0; i < 30; i++) {
    taken[i] = false;
  }

  // initial string
  for (int i = 0; i < a; i++) {
    taken[i] = true;
    s += 'a' + i;
  }

  // B move
  for (int i = 0; i < b; i++) {
    taken[i] = false;
    if (b >= a) {
      taken[s[a-1] - 'a'] = true;
      s += s[a-1];
    } else {
      taken[s[a-b-1] - 'a'] = true;
      s += s[a-b-1];
    }
  }

  size_t count = 0;

  // first comp move
  for (int i = 0; count < a;i++) {
    if (!taken[i]) {
      c = 'a' + i;
      s += c;
      count++;
    }
  }

  // B move
  for (int i = 0; i < b; i++) {
    s += c;
  }

  for (int i = 0; i < 30; i++) {
    taken[i] = false;
  }
  int mmax = 0;
  for (int i = 0; i < s.length(); i++) {
    if (!taken[s[i]-'a']) {
      taken[s[i]-'a'] = true;
      mmax++;
    }
  }
  for (int i = 0; i < 30; i++) {
    taken[i] = false;
  }

  int len = s.length();
  int k_l = l/len;
  r -= k_l*len;
  l -= k_l*len;
  if (l == 0) {
    r += len;
    l += len;
  }

  count = 0;
  l--; r--;
  s += s;
  s += s;

  for (int i = l; (i <= r) && (count < mmax); i++) {
    if (!taken[s[i]-'a']) {
      taken[s[i]-'a'] = true;
      count++;
    }
  }
  return count;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> a >> b >> l >> r;

  cout << min(simulate_a(l, r), simulate_b(l, r));
  return 0;
}
