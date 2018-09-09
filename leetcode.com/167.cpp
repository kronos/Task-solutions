class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2);
        int l = 0;
        int r = numbers.size()-1;
        while (l < r) {
            int q = numbers[l] + numbers[r];
            if (q < target) {
                l++;
            } else if (q > target) {
                r--;
            } else {
                ans[0] = l+1; ans[1] = r+1;
                break;
            }
        }

        return ans;
    }
};
