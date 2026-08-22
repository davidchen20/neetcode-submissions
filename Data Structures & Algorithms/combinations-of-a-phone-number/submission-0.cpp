class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mappings;
        mappings['2'] = "abc";
        mappings['3'] = "def";
        mappings['4'] = "ghi";
        mappings['5'] = "jkl";
        mappings['6'] = "mno";
        mappings['7'] = "pqrs";
        mappings['8'] = "tuv";
        mappings['9'] = "wxyz";

        vector<string> ans;
        string path;

        if (digits == "") return ans;
        
        dfs(ans, path, mappings, digits, 0);

        return ans;
    }

    void dfs(vector<string>& ans, string& path, unordered_map<char, string>& mappings, string& digits, int i) {
        if (i == digits.size()) {
            ans.push_back(path);
            return;
        } else {
            string& possible = mappings[digits[i]];
            for (int j = 0; j < possible.size(); j++) {
                path.push_back(possible[j]);
                dfs(ans, path, mappings, digits, i + 1);
                path.pop_back();
            }
        }
    }
};
