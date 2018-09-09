class Solution {
    void _subsets(vector<vector<int>>& ans, const vector<int>& nums, size_t idx, vector<int>& c) {
        if (idx == nums.size()) {
            ans.push_back(c);
        } else {
            _subsets(ans, nums, idx+1, c);
            c.push_back(nums[idx]);
            _subsets(ans, nums, idx+1, c);
            c.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> c;
        _subsets(ans, nums, 0, c);
        return ans;
    }
};
