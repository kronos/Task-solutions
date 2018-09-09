class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size(), idx;
        for (int i = 0; i < n; i++) {
            idx = abs(nums[i]) - 1;
            if (nums[idx] < 0) {
                ans.push_back(idx+1);
            } else {
                nums[idx] = -nums[idx];
            }
        }
        return ans;
    }
};
