class Solution {
public:
    vector<vector<string>> partition(string s) {
        // at every place choose whether you want to cut or not
        // promising is if the current cut is still a palindrome

        vector<vector<string>> ans;
        vector<string> path;

        dfs(ans, path, s, 0);

        return ans;
    }

    void dfs(vector<vector<string>>& ans, vector<string>& path, string& s, int i) {
        if (i >= s.size()) {
            // add the palindromes
            ans.push_back(path);
            return;
        } else {
            for (int j = i; j < s.size(); j++) {
                if (!isPalindrome(i, j, s)) continue;

                path.push_back(s.substr(i, j - i + 1));
                dfs(ans, path, s, j + 1);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(int left, int right, string& s) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }

        return true;
    }
};
