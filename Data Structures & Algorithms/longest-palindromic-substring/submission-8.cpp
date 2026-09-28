class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int end = 0;
        for (int i = 0; i < s.size(); i++) {
            // odd length palindromes
            int left = i;
            int right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                if (right - left + 1 > end - start + 1) {
                    start = left;
                    end = right;
                }

                left--;
                right++;
            }

            // even length palindromes
            left = i;
            right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                if (right - left + 1 > end - start + 1) {
                    start = left;
                    end = right;
                }

                left--;
                right++;
            }
        }

        return s.substr(start, end - start + 1);
    }
};
