class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string morse[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> result;
        string s;
        for (int i = 0; i < words.size(); i++) {
            s = "";
            for (int j = 0; j < words[i].length(); j++) {
                s += morse[words[i][j]-'a'];
            }
            result.insert(s);
        }
        return result.size();
    }
};
