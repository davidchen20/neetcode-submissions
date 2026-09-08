class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> m;

        int left = 0; 

        int maxCharacter = 0;
        int maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            m[s[right]]++;
            maxCharacter = max(maxCharacter, m[s[right]]);

            while ((right - left + 1) - maxCharacter > k) {
                m[s[left]]--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

         return maxLen;
    }
};
