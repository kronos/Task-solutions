class Solution {
public:
    string convertToTitle(int n) {
        string s = "";
        while (n > 0) {
            if (n%26 == 0) {
                s = "Z" + s;
                if (n == 26) {
                    break;
                }
                n = n/26-1;
            } else {
                s = char('@' + n%26) + s;
                n/=26;
            }
        }
        return s;
    }
};
