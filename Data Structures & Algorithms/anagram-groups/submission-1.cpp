class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); i++) {
            vector<int> counts(26);
            for (int j = 0; j < strs[i].size(); j++) {
                counts[strs[i][j] - 'a']++;
            }

            string key = "";
            for (int j = 0; j < counts.size(); j++) {
                key += to_string(counts[j]) + ",";
            }
            
            m[key].push_back(strs[i]);
        }

        for (auto &pair : m) {
            ans.push_back(pair.second);
        }

        return ans;
    }
};
