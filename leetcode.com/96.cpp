class Solution {
public:
    int numTrees(int n) {
        vector<int> a(n+1);
        a[0] = 1;
        a[1] = 1;
        for (int i = 2; i <= n; i++) {
            a[i] = 0;
            for (int j = 0; j < i; j++) {
                a[i] += a[j]*a[i-1-j];
            }
        }
        return a[n];
    }
};
