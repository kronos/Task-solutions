class Solution {
public:
    int numJewelsInStones(string J, string S) {
        bool jewels[60];
        int result = 0;
        for (int i = 0; i < 60; i++) {
            jewels[i] = false;
        }

        for (int i = 0; i < J.size(); i++) {
            jewels[J[i] - 'A'] = true;
        }

        for (int i = 0; i < S.size(); i++) {
            if (jewels[S[i]-'A']) {
                result++;
            }
        }
        return result;
    }
};
