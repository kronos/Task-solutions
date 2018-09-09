class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        if (A.size()) {
            int n = A.size();
            int m = A[0].size();
            vector<vector<int>> B(m);
            for (int j = 0; j < m;j++) {
                vector<int> row(n);
                for (int i = 0; i < n; i++) {
                    row[i] = A[i][j];
                }
                B[j] = row;
            }
            return B;
        } else {
            return A;
        }

    }
};
