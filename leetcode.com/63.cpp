class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        if (!n) {
            return 0;
        }
        int m = obstacleGrid[0].size();
        if (m) {
            vector<int> P[2];
            int r = 1;
            for (int i = 0; i < m; i++) {
                if (obstacleGrid[0][i] == 1) {
                    r = 0;
                }
                P[0].push_back(r);
                P[1].push_back(r);
            }
            int k = 0;
            for (int i = 1; i < n; i++) {
                k = 1 - k;
                if (obstacleGrid[i][0] == 1) {
                    P[k][0] = 0;
                } else {
                    P[k][0] = P[1-k][0];
                }
                for (int j = 1; j < m; j++) {
                    if (obstacleGrid[i][j] == 1) {
                        P[k][j] = 0;
                    } else {
                        P[k][j] = P[k][j-1] + P[1-k][j];
                    }
                }
            }
            return P[k][m-1];
        } else {
            return 0;
        }
    }
};
