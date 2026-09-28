class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // catsincars
        // cats incars

        // cats in cars

        // cat sincars

        // cat sin cars
        // cat sin car s
        vector<bool> memo(s.size());
        // memo[i] = can i partition you with the word dict up to index i

        for (int i = 0; i < wordDict.size(); i++) {
            string& word = wordDict[i];

            if (word.size() <= s.size()) {
                if (word == s.substr(0, word.size())) {
                    memo[word.size()-1] = true;
                }
            }
        }

        for (int i = 1; i < s.size(); i++) {
            for (string& word : wordDict) {
                int wordLength = word.size();
                int startIdx = i - wordLength + 1;
                if (startIdx >= 0 && !memo[i]) {
                    if (word == s.substr(startIdx, wordLength) && (memo[startIdx - 1 ] || startIdx == 0)) memo[i] = true;
                }
            }
        }

        return memo[s.size() - 1];
        // memo[i+word.size()] = word == s[i + word.size()] && memo[i]
        // memo[i] = word == s[i - word.size()] && memo[i-word.size()];
    }
};
