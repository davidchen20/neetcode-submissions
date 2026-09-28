class Solution {
public:
    int numDecodings(string s) {
        // 12

        // 1 2
        // 12

        // 01
        // 1

        // define memo to be the max number of decodings from index i onwards

        vector<int> memo(s.size());
        memo[s.size() - 1] = s[s.size() - 1] == '0' ? 0 : 1;
        for (int i = s.size() - 2; i >= 0; i--) {
            if (s[i] == '0') {
                memo[i] = 0;
                continue;
            }

            // do on digit
            memo[i] += memo[i + 1];

            // two digit
            if (s[i] == '1' && i + 1 < s.size()) {
                memo[i] += i + 2 < s.size() ? memo[i+2] : 1;
            } else if (s[i] == '2' && i + 1 < s.size() && s[i+1] - '0' < 7) {
                memo[i] += i + 2 < s.size() ? memo[i+2] : 1;
            }
        }

        return memo[0];
    }
};
