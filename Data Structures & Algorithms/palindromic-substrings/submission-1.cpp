class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> memo(s.size(), vector<bool>(s.size()));

        int count = 0;
        for (int len = 1; len <= s.size(); len++) {
            for (int i = 0; i + len - 1 < s.size(); i++) {
                int endIdx = i + len - 1;
                if (len == 1) {
                    memo[i][endIdx] = true;
                } else if (len == 2) {
                    memo[i][endIdx] = s[i] == s[endIdx];
                } else {
                    memo[i][endIdx] = s[i] == s[endIdx] && memo[i+1][endIdx-1];
                }

                if (memo[i][endIdx]) count++;
            }
        }

        return count;
    }
};
