class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        set<int> seen;
        int n = nums.size();
        int idx;
        for (int i = 0; i < n; i++) {
            idx = abs(nums[i]) - 1;
            if (nums[idx] > 0) {
                nums[idx] = -nums[idx];
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};
