class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mmax = 1;
        int mmin = 1;
        int ans = INT_MIN;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if (nums[i] == 0){
                mmax = 1;
                mmin = 1;
                ans = max(ans, 0);
            } else {
                int t = mmax;
                mmax = max(mmin*nums[i], max(mmax*nums[i], nums[i]));
                mmin = min(mmin*nums[i], min(t*nums[i], nums[i]));
                ans = max(ans, mmax);
            }
        }

        return ans;
    }
};
