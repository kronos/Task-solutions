#include <iostream>

using namespace std;
int ans;
int a[100000];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n-1; i++) {
        if (!((a[i] + a[i+1]) & 1)) {
            ans++;
            a[i+1] = a[i];
        }
    }
    cout << ans;
    return 0;
}
