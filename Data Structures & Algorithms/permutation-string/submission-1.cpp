class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        vector<int> s1Counts(26);

        for (int i = 0; i < s1.size(); i++) {
            s1Counts[s1[i] - 'a']++;
        }
        
        vector<int> s2Counts(26);
        for (int i = 0; i < s2.size(); i++) {
            s2Counts[s2[i] - 'a']++;

            if (i >= s1.size() - 1) {
                if (s1Counts == s2Counts) return true;
                int startWindowIdx = i - (s1.size() - 1);
                s2Counts[s2[startWindowIdx] - 'a']--;
            }
        }

        return false;
    }
};
