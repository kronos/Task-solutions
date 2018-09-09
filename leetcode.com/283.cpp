class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                if (i > pos) {
                    nums[pos]=nums[i];
                    nums[i]=0;
                }
                pos++;
            }
        }
    }
};
