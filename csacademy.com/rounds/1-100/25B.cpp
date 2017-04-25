#include <iostream>
#include <algorithm>

using namespace std;

int a[100002];

int main() {
    int n, d = 0, left, right;
    cin >> n;

    if (n == 1) {
        d = 100000;
    } else {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a+n);

        for (int i = 1; i < n; i++) {
            if (a[i+1] - a[i-1] - 1 > d) {
                d = a[i+1] - a[i-1] - 1;
            }
        }

        left = a[1] - 1;
        if (a[0] == 1) {
            left--;
        }
        d = max(left, d);
        right = 100000 - a[n-2];
        if (a[n-1] == 100000) {
            right--;
        }
        d = max(right, d);
    }
    cout << d;
    return 0;
}
