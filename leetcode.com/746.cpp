class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (!cost.size()) {
            return 0;
        }
        if (cost.size() == 1) {
            return cost[0];
        }
        int n = cost.size();
        vector<int> ans(n+1, 0);
        ans[0] = cost[0];
        ans[1] = cost[1];
        for (int i = 2; i < n; i++) {
            ans[i] = min(ans[i-1], ans[i-2]) + cost[i];
        }
        return min(ans[n-1], ans[n-2]);
    }
};
