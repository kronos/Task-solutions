class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, vector<int> > m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]].push_back(i);
        }

        for (map<int, vector<int> >::iterator it = m.begin(); it != m.end(); it++) {
            for (int i = it->second.size()-1; i > 0; i--) {
                if (it->second[i] - it->second[i-1] <= k) {
                    return true;
                }
            }
        }

        return false;
    }
};
