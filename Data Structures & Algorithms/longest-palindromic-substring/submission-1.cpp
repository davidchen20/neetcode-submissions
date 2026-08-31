class Solution {
public:
    string longestPalindrome(string s) {
        int ansLeft = 0;
        int ansRight = 0;
        // for each char in the string, expand outward until it is no longer a palindrome 
        for (int i = 0; i < s.size(); i++) {
            // check odd length palindromes
            int left = i;
            int right = i;
            while (right < s.size() && left >= 0 && s[left] == s[right]) {
                if (right - left + 1 > ansRight - ansLeft + 1)  {
                    ansRight = right;
                    ansLeft = left;
                }

                right++;
                left--;
            }

            // check the even length palindromes
            left = i;
            right = i + 1;
            while (right < s.size() && left >= 0 && s[left] == s[right]) {
                if (right - left + 1 > ansRight - ansLeft + 1)  {
                    ansRight = right;
                    ansLeft = left;
                }

                right++;
                left--;
            }
        }

        return s.substr(ansLeft, ansRight - ansLeft + 1);
    }
};
