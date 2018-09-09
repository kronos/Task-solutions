class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        map<int,bool> m;
        for (int i = 0; i < n; i++) {
            m[nums[i]] = true;
        }
        int i = 0;
        int n = nums.size();
        int j = n - 1;
        while (i < j) {
            if (m.find(- nums[i] - nums[j]) != m.end()) {

            }
            int k = i;
            while(nums[k] == nums[i] && i < j) {
                i++;
            }
            k = j;
            while(nums[k] == nums[j] && j > i) {
                j--;
            }
        }

        return ans;
    }
};

