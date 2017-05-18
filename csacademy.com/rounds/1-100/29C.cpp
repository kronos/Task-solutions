#include <iostream>
#include <algorithm>

using namespace std;
int a[100001];
int n;

int main() {
    int k,x;
    cin >> n >> k;
    long long ans = 0;
    int l = 100000;
    int r = 1;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[x]++;
        if (x < l) {
            l = x;
        }

        if (x > r) {
            r = x;
        }
    }

    while (r-l > k) {
        x = min(a[l], a[r]);
        ans += x;
        a[l] -= x;
        a[r] -= x;
        a[l+1] += x;
        a[r-1] += x;
        if (a[l] == 0) {
            l++;
        }

        if (a[r] == 0) {
            r--;
        }

    }
    cout << ans << endl;
    return 0;
}
