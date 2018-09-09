class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n > 9) {
            return 0;
        }

        vector<int> ans(n+1, 0);
        ans[0] = 1;
        ans[1] = 10;
        int p = 9;
        for (int i = 2; i <= n; i++) {
            p *= 11-i;
            ans[i] = ans[i-1] + p;
        }
        return ans[n];
    }
};
