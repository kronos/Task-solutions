class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int sum = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i] + sum) {
                sum = nums[i];
            } else {
                sum += nums[i];
            }

            ans = max(ans, sum);
        }
        return ans;
    }
};
