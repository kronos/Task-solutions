#include <iostream>
#include <algorithm>

using namespace std;

int a[100000];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n, count = 0, e;
  int answer;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> e;
    if (e != 0) {
      a[count++] = e;
    }
  }

  sort(a, a + count);
  if (a[count-1] < 0) {
    for (int i = count-1; i>=0; i--) {
      if (a[i] % 2 != 0) {
        answer = a[i];
        break;
      }
    }
  } else {
    bool odd_negative = false;
    int biggest_odd_negative;
    int smallest_odd_positive;
    bool odd_positive = false;
    int even_sum = 0;
    int odd_sum = 0;

    for (int i = 0; i < n; i++) {
      if (a[i] % 2 != 0) {
        if (a[i] > 0) {
          odd_sum += a[i];
          if (!odd_positive) {
            odd_positive = true;
            smallest_odd_positive = a[i];
          }
        } else {
          odd_negative = true;
          biggest_odd_negative = a[i];
        }
      } else if (a[i] > 0) {
        even_sum += a[i];
      }
    }

    odd_sum += even_sum;
    if (odd_sum % 2 == 0) {
      if (odd_negative && odd_positive) {
        answer = max(odd_sum - smallest_odd_positive, odd_sum + biggest_odd_negative);
      } else if (odd_positive) {
        answer = odd_sum - smallest_odd_positive;
      } else if (odd_negative) {
        answer = odd_sum + biggest_odd_negative;
      } else {
        throw 20;
      }
    } else {
      answer = odd_sum;
    }
  }

  cout << answer << endl;
  return 0;
}
