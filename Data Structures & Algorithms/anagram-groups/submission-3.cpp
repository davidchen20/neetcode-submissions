class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // create a counts vector for each string and for the anagrams vector compare it to first element of each one to find if its equal, if it is equal to none just make a new one

        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;

        for (int i = 0; i < strs.size(); i++) {
            string& curr = strs[i];

            vector<int> counts(26);
            for (int j = 0; j < curr.size(); j++) {
                counts[curr[j] - 'a']++;
            }

            // hash this counts vector
            string key = "";
            for (int j = 0; j < counts.size(); j++) {
                key += to_string(counts[j]) + " ";
            }

            m[key].push_back(curr);
        }

        for (auto& pair : m) {
            ans.push_back(pair.second);
        }

        return ans;
    }
};
