#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;
int n;
long long a[50];
long long k, p, q;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> k;

  n = 50;
  p = k % n;
  q = k / n;

  for (long long i = 0; i < n; i++) {
    a[i] = 49LL + q - p;
  }

  for (long long i = 0; i < p; i++) {
    a[i] = 100LL + q - p;
  }

  cout << n << "\n";
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  return 0;
}

// {49} => 0
// {49*48,  1*99}   => 1
// {48*47,  2*98}   => 2
// {47*46,  3*97}   => 3
// {46*45,  4*96}   => 4
// { 0*0,  50*50}   => 50
// {49*49,  1*100}  => 51
// {48*48,  2*99}   => 52
// { 1*1,  49*52}   => 99
// { 0*0,  50*51}   => 100
// { 49*50, 1*101}  => 101
// { 48*49, 2*100}  => 102
// { 2*3,  48*54}   => 148
// { 1*2,  49*53}   => 149
// { 0*0,  50*52}   => 150


// 50*(50 + q - 1) => q * 50
