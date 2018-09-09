class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        ans[0] = nums[0];
        for (int i = 1; i < n ; i++) {
            ans[i] = ans[i-1] * nums[i];
        }
        ans[n-1] = ans[n-2];
        int p = nums[n-1];
        for (int i = n-2; i > 0; i--) {
            ans[i] = ans[i-1]*p;
            p *= nums[i];
        }
        ans[0] = p;
        return ans;
    }
};
