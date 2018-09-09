bool cmp(const vector<int>& l, const vector<int>& r) {
    return l[1] < r[1];
}

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);
        int ans = 0;
        int g = -100000;
        for (int i = 0; i < pairs.size(); i++) {
            if (pairs[i][0] > g) {
                ans++;
                g = pairs[i][1];
            }
        }
        return ans;
    }
};
