class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int imin = 0;
        for (int i = 1; i < prices.size(); i++) {
            ans = max(ans, prices[i] - prices[imin]);

            if (prices[i] < prices[imin]) {
                imin = i;
            }
        }
        return ans;
    }
};
