class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> memo(s.size(), vector<bool>(s.size(), false));
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            memo[i][i] = true;
            count++;
        }

        for (int length = 2; length <= s.size(); length++) {
            for (int start = 0; start <= s.size() - length; start++) {
                int end = start + length - 1;
                if (memo[start][end]) {
                    continue;
                } else {
                    memo[start][end] = s[start] == s[end] && (length == 2 || memo[start+1][end-1]);
                    if (memo[start][end]) count++;
                }
            }
        }

        return count;
    }
};
