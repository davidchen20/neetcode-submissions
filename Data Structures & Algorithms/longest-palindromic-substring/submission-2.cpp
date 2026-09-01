class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> memo(s.size(), vector<int>(s.size(), -1));

        int ansLeft = 0;
        int ansRight = 0;
        for (int left = 0; left < s.size(); left++) {
            for (int right = left; right < s.size(); right++) {
                if (isPalindrome(memo, s, left, right)) {
                    if (right - left + 1 > ansRight - ansLeft + 1) {
                        ansRight = right;
                        ansLeft = left;
                    }
                }
            }
        }

        return s.substr(ansLeft, ansRight - ansLeft + 1);
    }


    // returns if the string between index left and right inclusive is a palindrome or not
    bool isPalindrome(vector<vector<int>>& memo, string& s, int left, int right) {
        if (left >= right) return true;
        if (memo[left][right] != -1) return memo[left][right];

        memo[left][right] = s[left] == s[right] && isPalindrome(memo, s, left + 1, right - 1) ? 1 : 0;
        return memo[left][right];
    } 
};
