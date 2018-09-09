class Solution {
    bool visited[50][50];
    int n, m;
public:
    int area(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || grid[i][j] == 0) {
            return 0;
        }
        visited[i][j] = true;
        return 1 + area(grid, i-1, j) + area(grid, i+1, j) + area(grid, i, j - 1) + area(grid, i, j + 1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                visited[i][j] = grid[i][j] == 0;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]  && grid[i][j] == 1) {
                    ans = max(ans, area(grid, i, j));
                }
            }
        }

        return ans;
    }
};
