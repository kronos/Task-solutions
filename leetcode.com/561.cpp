class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        size_t size = nums.size();
        int r = 0 ;
        for (int i = 0; i < nums.size(); i+= 2) {
            r += min(nums[i], nums[i+1]);
        }
        return r;
    }
};
