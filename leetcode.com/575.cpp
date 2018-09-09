class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        set<int> m;
        int n = candies.size();

        for (int i = 0; i < n; i++) {
            m.insert(candies[i]);
        }

        return min((int)m.size(), n/2);
    }
};
