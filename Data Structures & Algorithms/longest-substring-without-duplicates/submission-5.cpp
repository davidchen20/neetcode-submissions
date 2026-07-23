class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxLength = 0;
        unordered_set<char> characters;

        for (int right = 0; right < s.size(); right++) {
            while(characters.count(s[right])) {
                characters.erase(s[left]);
                left++;
            }

            characters.insert(s[right]);

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
