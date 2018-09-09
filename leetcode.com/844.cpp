class Solution {
public:
    bool backspaceCompare(string S, string T) {
        bool ans = true;
        int si = S.length() - 1;
        int ti = T.length() - 1;
        int acc;

        while (si >= 0 && ti >= 0 && ans) {
            acc = 0;
            while (si >= 0 && (S[si] == '#' || acc > 0)) {
                if (S[si] == '#') {
                    acc++;
                } else {
                    acc--;
                }
                si--;
            }
            acc = 0;
            while (ti >= 0 && (T[ti] == '#' || acc > 0)) {
                if (T[ti] == '#') {
                    acc++;
                } else {
                    acc--;
                }
                ti--;
            }

            if (si >= 0 && ti >= 0) {
                ans = S[si] == T[ti];
                si--;
                ti--;
            } else {
                ans = si < 0 && ti < 0;
            }
        }
        acc = 0;
        while (si >= 0 && (S[si] == '#' || acc > 0)) {
            if (S[si] == '#') {
                acc++;
            } else {
                acc--;
            }
            si--;
        }
        acc = 0;
        while (ti >= 0 && (T[ti] == '#' || acc > 0)) {
            if (T[ti] == '#') {
                acc++;
            } else {
                acc--;
            }
            ti--;
        }
        ans &= ti < 0 && si < 0;
        return ans;
    }
};
