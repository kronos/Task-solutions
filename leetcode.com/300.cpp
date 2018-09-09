class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        vector<int> d(n+1);
        d[0] = std::numeric_limits<int>::min();
        for (int i = 1; i < n; i++) {
            d[1] = std::numeric_limits<int>::max();
        }
        int ans = 1;
        for (int i = 0; i <= n; i++) {
            for (int j = 1; j < n; j++) {
                if (nums[i] > nums[j]) {
                    d[i] = max(d[i], 1 + d[j]);
                    ans = max(ans, d[i]);
                }
            }
        }

        return ans;
    }
};
