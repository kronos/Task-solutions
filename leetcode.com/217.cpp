class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       set<int> was;
       for (int i = 0; i < nums.size(); i++) {
           if (was.find(nums[i]) != was.end()) {
               return true;
           }
           was.insert(nums[i]);
       }
        return false;
    }
};
