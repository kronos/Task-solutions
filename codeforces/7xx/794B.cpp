#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>

using namespace std;
int n;
long double h,ans;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> n >> h;
  long double square =  h*0.5;
  long double sq = square / n;
  long double p = square - sq;
  long double l = 0.0;
  long double r = h;
  long double mid;
  long double a,x,b;
  while (r-l > 1e-8) {
    mid = (r+l)/2.0;
    x = 2*sq/mid;
    if (p - (x+1)*(h-mid)*0.5 > 1e-8) {
      r = mid;
    } else {
      l = mid;
    }
  }

  printf("%.11Lf ", mid);
  ans = mid;

  for (int i = 1; i < n-1; i++) {
    h -= mid;
    p = square - (i+1)*sq;
    a = x;
    l = 0.0;
    r = h;
    while (r-l > 1e-8) {
      mid = (r+l)/2.0;
      x = 2*sq/mid - a;
      if (p - (x+1)*(h-mid)*0.5 > 1e-8) {
        r = mid;
      } else {
        l = mid;
      }
    }
    ans += mid;
    printf("%.11Lf ", ans);
  }
  return 0;
}
