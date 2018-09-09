class NumMatrix {
    int **sum;
public:
    NumMatrix(vector<vector<int>> matrix) {
        int n = matrix.size();
        if (n > 0) {
            int m = matrix[0].size();
            if (m > 0) {
                sum = new int*[n];
                sum[0] = new int[m];
                sum[0][0] = matrix[0][0];
                for (int j = 1; j < m; j++) {
                    sum[0][j] = matrix[0][j]+sum[0][j-1];
                }
                for (int i = 1; i < n; i++) {
                    sum[i] = new int[m];
                    sum[i][0] = matrix[i][0] + sum[i-1][0];
                    for (int j = 1; j < m; j++) {
                        sum[i][j] = matrix[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
                    }
                }
            }
        }

    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = sum[row2][col2];
        if (row1 > 0) {
            ans -= sum[row1-1][col2];
        }

        if (col1 > 0) {
            ans -= sum[row2][col1-1];
        }
        if (col1 > 0 && row1 > 0) {
            ans += sum[row1-1][col1-1];
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
