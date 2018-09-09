

class Solution {
public:
    int majorityElement(vector<int> &num) {
        unsigned freq = 1;
        int r = num[0];
        for(size_t i = 1; i < num.size(); i++) {
            if (num[i] == r) {
                freq++;
            } else {
                freq--;
                if (freq == 0) {
                    freq = 1;
                    r = num[i];
                }
            }
        }
        return r;
    }
};
