class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans;
        for (int i = 0, j = 0; i < n && j < m;) {
            while (i < n && nums1[i] < nums2[j]) {
                i++;
            }

            if (i < n) {
                int q = nums1[i];
                if (q == nums2[j]) {
                    ans.push_back(q);
                    do {
                        i++;
                    } while (i < n && nums1[i] == q);
                    do {
                        j++;
                    } while (j < m && nums2[j] == q);
                } else {
                    j++;
                }
            }
        }

        return ans;
    }
};
