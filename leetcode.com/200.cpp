class Solution {
    int n, m;
public:
    void mark(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        mark(grid, i-1, j);
        mark(grid, i+1, j);
        mark(grid, i, j - 1);
        mark(grid, i, j + 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        n = grid.size();
        if (n == 0) {
            return 0;
        }
        m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    mark(grid, i, j);
                }
            }
        }

        return ans;
    }
};
