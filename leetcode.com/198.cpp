class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        }
        if (len == 1) {
            return nums[0];
        }
        vector<int> ans(len);
        ans[0] = nums[0];
        ans[1] = nums[1];
        if (len == 2) {
            return max(ans[0], ans[1]);
        }
        ans[2] = nums[0] + nums[2];
        if (len == 3) {
            return max(ans[1], ans[2]);
        }

        for (int i = 3; i < len; i++) {
            ans[i] = nums[i]+ max(ans[i-3], ans[i-2]);
        }

        return max(ans[len-1], ans[len-2]);
    }
};
