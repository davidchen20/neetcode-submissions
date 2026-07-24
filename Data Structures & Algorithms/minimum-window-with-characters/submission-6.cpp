class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";
        int left = 0; 
        int minLength = INT_MAX;
        int leftIndex = -1;
        int rightIndex = -1;

        unordered_map<char, int> counts;
        unordered_map<char, int> windowCounts;

        int distinctChars = 0;

        for (int i = 0; i < t.size(); i++) {
            counts[t[i]]++;
            windowCounts[t[i]] = 0;
        }

        for (int right = 0; right < s.size(); right++) {
            auto it = counts.find(s[right]);
            if (it != counts.end()) {
                char c = it->first;
                windowCounts[c]++;

                // make sure you only increment it after the needed number of the character is satisfied
                if (windowCounts[c] == counts[c]) distinctChars++; 
            }

            auto countsIt = counts.find(s[left]);
            auto windowCountsIt = windowCounts.find(s[left]);
            while ((left <= right) && (countsIt == counts.end()) || (countsIt != counts.end() && countsIt->second - windowCountsIt->second < 0)) {
                if (countsIt != counts.end()) {
                    windowCounts[windowCountsIt->first]--;
                    if (windowCounts[windowCountsIt->first] == 0) distinctChars--;
                }
                left++;
                countsIt = counts.find(s[left]);
                windowCountsIt = windowCounts.find(s[left]);
            }

            if (counts.size() == distinctChars) {
                if (minLength > right - left + 1) {
                    minLength = right - left + 1;
                    leftIndex = left;
                    rightIndex = right;
                }
            }
        }

        if (leftIndex < 0 && rightIndex < 0) return "";
        return s.substr(leftIndex, minLength);
    }
};
