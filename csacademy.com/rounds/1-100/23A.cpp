#include <iostream>

using namespace std;
int a[100][100];
int vic[100];

int main() {
    int sum = 0, idx = 0, n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i< n; i++) {
        for (int j = 0; j< n; j++) {
            if (i != j) {
                if (a[i][j] == 1) {
                    vic[i]++;
                } else {
                    vic[j]++;
                }
            }
        }
    }

    for (int i = 1; i< n;i++) {
        if (vic[i] > vic[idx]) {
            idx = i;
        }
    }

    cout << idx+1;
    return 0;
}
