class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> r;
                     // a b c d e f g h i j k l m n o p q r s t u v w x y z
        char chars[] = {2,3,3,2,1,2,2,2,1,2,2,2,3,3,1,1,1,1,2,1,1,3,1,3,1,3};
        for (string word : words) {
            int pos = chars[tolower(word[0])-'a'];
            bool good = true;
            for (int i = 1; (i < word.length()) && good;i++) {
                good = chars[tolower(word[i])-'a'] == pos;
            }

            if (good) {
                r.push_back(word);
            }
        }
        return r;
    }
};
