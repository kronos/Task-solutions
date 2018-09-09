class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int dp[1001][1001];
        dp[s1.length()][s2.length()] = 0;
        for (int i = s1.length() - 1; i >= 0; i--) {
            dp[i][s2.length()] = dp[i+1][s2.length()] + s1[i];
        }
        for (int j = s2.length() - 1; j >= 0; j--) {
            dp[s1.length()][j] = dp[s1.length()][j+1] + s2[j];
        }

        for (int i = s1.length() - 1; i >= 0; i--) {
            for (int j = s2.length() - 1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i+1][j+1];
                } else {
                    dp[i][j] = min(dp[i+1][j]+s1[i], dp[i][j+1]+s2[j]);
                }
            }
        }
        return dp[0][0];
    }
};
