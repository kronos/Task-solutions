class Solution {
public:
    int integerBreak(int n) {
        vector<int> ans(n+1, 0);
        ans[1] = 1;

        for (int i = 2; i <= n; i++) {
            ans[i] = i - 1;
            for (int j = 1; j <= i/2; j++) {
                ans[i] = max(ans[i], max(ans[j], j)*max(ans[i-j], i-j));
            }
        }

        return ans[n];
    }
};
