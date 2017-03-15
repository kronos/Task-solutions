#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct good
{
  int before;
  int after;
};

bool comparator(const good& left, const good& right)
{
  int a = left.before - left.after;
  int b = right.before - right.after;
  return a < b;
}

int i,j,k,n;
good a[200001];

int main() {
  cin >> n >> k;
  for (i = 0; i < n; i++) {
    cin >> a[i].before;
  }
  for (i = 0; i < n; i++) {
    cin >> a[i].after;
  }
  vector<good> goods (a, a+n);
  sort(goods.begin(), goods.end(), comparator);
  unsigned long long int answer = 0;

  for (i = 0; i<n; ) {
    if (k > 0) {
      answer += goods[i].before;
      k--;
    } else {
      if (goods[i].before <= goods[i].after) {
        answer += goods[i].before;
      } else {
        break;
      }
    }
    i++;
  }
  for (; i<n; i++) {
    answer += goods[i].after;
  }
  cout << answer;

  return 0;
}
