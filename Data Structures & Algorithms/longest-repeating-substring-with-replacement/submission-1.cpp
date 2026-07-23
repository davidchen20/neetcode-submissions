class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxCharacter = 0;
        int maxLength = 0;
        unordered_map<char, int> characters;

        for (int right = 0; right < s.size(); right++) {
            // Expand the window
            characters[s[right]]++;
            maxCharacter = max(characters[s[right]], maxCharacter);
            
            while ((right - left + 1) - maxCharacter > k) {
                if (characters[s[left]] == 1) {
                    characters.erase(s[left]);
                } else {
                    characters[s[left]]--;
                }

                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        } 

        return maxLength;
    }
};
