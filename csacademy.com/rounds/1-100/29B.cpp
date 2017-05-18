#include <iostream>
#include <algorithm>

using namespace std;
int main() {
    int n;
    cin >> n;
    int ans, a;
    int q = 0, l = -1, r;

    for (int i = 0; i < n; i++) {
        cin >> a;
        q = a^q;
        if (a > 0 && l == -1) {
            l = i;
        }

        if (a > 0) {
            r = i;
        }
    }

    if (l == -1) {
        ans = 0;
    } else if (q) {
        ans = n;
    } else {
        ans = max(r, n-l-1);
    }

    cout << ans;
    return 0;
}
