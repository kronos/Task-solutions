class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int ans = 0;

        int n = grid.size();
        if (n) {
            int m = grid[0].size();
            for (int j = 1; j < m; j++) {
                grid[0][j] += grid[0][j-1];
            }

            for (int i = 1; i < n; i++) {
                grid[i][0] += grid[i-1][0];
            }
            for (int i = 1; i < n; i++) {
                for (int j = 1; j < m; j++) {
                    grid[i][j] = grid[i][j] + min(grid[i-1][j], grid[i][j-1]);
                }
            }
            ans = grid[n-1][m-1];
        }
        return ans;
    }
};
