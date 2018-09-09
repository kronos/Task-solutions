class Solution {
public:
    int climbStairs(int n) {
        vector<int> A(n+1);
        A[0] = A[1] = 1;
        for (int i = 2; i <= n; i++) {
            A[i] = A[i-2] + A[i-1];
        }
        return A[n];
    }
};
