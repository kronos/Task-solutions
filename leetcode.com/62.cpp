class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m > 0 && n > 0) {
            vector<int> P[2];
            for (int i = 0; i < m; i++) {
                P[0].push_back(1);
                P[1].push_back(1);
            }
            int k = 0;
            for (int i = 1; i < n; i++) {
                k = 1 - k;
                P[k][0] = P[1-k][0];
                for (int j = 1; j < m; j++) {
                    P[k][j] = P[k][j-1] + P[1-k][j];
                }

            }
            return P[k][m-1];
        } else {
            return 0;
        }
    }
};
