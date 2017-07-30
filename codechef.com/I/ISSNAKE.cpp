#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int len;
string s[2];

int left_to_right(int it, int jt) {
  int ans = 1;
  bool has_way = true;
  bool top_visited = it == 0;
  bool bottom_visited = it == 1;
  while (has_way) {
    has_way = false;
    if (it == 0) {
      if (!bottom_visited && s[1][jt] == '#') {
        bottom_visited = true;
        has_way = true;
        ans++;
        it = 1;
      } else {
        if (jt+1 < len && s[0][jt+1] == '#') {
          ans++;
          jt++;
          bottom_visited = false;
          has_way = true;
        }
      }
    } else { // it == 1
      if (!top_visited && s[0][jt] == '#') {
        top_visited = true;
        has_way = true;
        ans++;
        it = 0;
      } else {
        if (jt+1 < len && s[1][jt+1] == '#') {
          ans++;
          jt++;
          top_visited = false;
          has_way = true;
        }
      }
    }
  }

  return ans;
}

int right_to_left(int it, int jt) {
  int ans = 1;
  bool has_way = true;
  bool top_visited = it == 0;
  bool bottom_visited = it == 1;
  while (has_way) {
    has_way = false;
    if (it == 0) {
      if (!bottom_visited && s[1][jt] == '#') {
        bottom_visited = true;
        has_way = true;
        ans++;
        it = 1;
      } else {
        if (jt > 0 && s[0][jt-1] == '#') {
          ans++;
          jt--;
          bottom_visited = false;
          has_way = true;
        }
      }
    } else { // it == 1
      if (!top_visited && s[0][jt] == '#') {
        top_visited = true;
        has_way = true;
        ans++;
        it = 0;
      } else {
        if (jt > 0 && s[1][jt-1] == '#') {
          ans++;
          jt--;
          top_visited = false;
          has_way = true;
        }
      }
    }
  }

  return ans;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int t, cnt, mcnt;
  int left_top, right_top, left_bottom, right_bottom;
  cin >> t;

  while (t--) {
    cin >> len;
    cin >> s[0];
    cin >> s[1];
    mcnt = cnt = 0;
    left_top = left_bottom = right_top = right_bottom = -1;

    for (int i = 0; i < len; i++) {
      if (s[0][i] == '#') {
        if (left_top == -1) {
          left_top = i;
        }
        cnt++;
        right_top = i;
      }

      if (s[1][i] == '#') {
        if (left_bottom == -1) {
          left_bottom = i;
        }
        cnt++;
        right_bottom = i;
      }
    }

    if (left_top < left_bottom) {
      mcnt = left_to_right(0, left_top);
    } else if (left_bottom < left_top) {
      mcnt = left_to_right(1, left_bottom);
    } else {
      mcnt = max(left_to_right(0, left_top), left_to_right(1, left_bottom));
    }

    if (mcnt < cnt) {
      if (right_top > right_bottom) {
        mcnt = right_to_left(0, right_top);
      } else if (right_bottom > right_top) {
        mcnt = right_to_left(1, right_bottom);
      } else {
        mcnt = max(right_to_left(0, right_top), right_to_left(1, right_bottom));
      }
    }

    if (mcnt == cnt) {
      cout << "yes\n";
    } else {
      cout << "no\n";
    }

  }
  return 0;
}
