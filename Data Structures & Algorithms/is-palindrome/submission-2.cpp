class Solution {
public:
    bool isPalindrome(string s) {
        // two pointers
        // one at start of string, one at end of string
        // keep looping until they hit the same character or pass each other

        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            while (left < right && !alphaNum(s[left])) left++;
            while (left < right && !alphaNum(s[right])) right--;

            if (tolower(s[left]) != tolower(s[right])) return false;

            left++;
            right--;
        }

        return true;
    }

    bool alphaNum(char c) {
        return (c >= 'A' && c <= 'Z' ||
                c >= 'a' && c <= 'z' ||
                c >= '0' && c <= '9');
    }
};
