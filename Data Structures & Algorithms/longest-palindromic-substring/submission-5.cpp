class Solution {
public:
    string longestPalindrome(string s) {
        // build the memo up from bottom up
        // memo[i][j] = true means that the string from index i to j is a palindrome
        vector<vector<bool>> memo(s.size(), vector<bool>(s.size(), false));

        // all one character long substrings are palindromes
        for (int i = 0; i < s.size(); i++) {
            memo[i][i] = true;
        }

        int ansLen = 1;
        int ansStart = 0;

        for (int length = 2; length <= s.size(); length++) {
            for (int start = 0; start <= s.size() - length; start++) {
                if (memo[start][start+length-1]) {
                    if (length > ansLen) {
                        ansLen = length;
                        ansStart = start;
                    }
                } else {
                    int end = start + length - 1;
                    memo[start][start+length-1] = s[start] == s[end] && (length == 2 ||memo[start+1][end-1]);
                    if (memo[start][start+length-1]) {
                        if (length > ansLen) {
                            ansLen = length;
                            ansStart = start;
                        }
                    }  
                }
            }
        }

        return s.substr(ansStart, ansLen);
    }
};
