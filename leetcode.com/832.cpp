class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int t;
        int cols = A[0].size();
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < cols/2; j++) {
                t = A[i][cols-j-1];
                A[i][cols-j-1] = A[i][j];
                A[i][j] = t;
            }
        }

        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < cols; j++) {
                A[i][j] = 1 - A[i][j];
            }
        }
        return A;
    }
};
