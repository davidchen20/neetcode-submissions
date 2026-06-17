class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for (int i = 0; i < strs.size(); i++) {
            encoded += to_string(strs[i].size()) + "#" + strs[i];
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        for (int i = 0; i < s.size(); ) {
            int stringLength;
            int startIdx = i;
            while (i < s.size() && s[i] != '#') {
                i++;
            }
            stringLength = stoi(s.substr(startIdx, i - startIdx));

            ans.push_back(s.substr(i+1, stringLength));
            i += 1 + stringLength;
        }

        return ans;
    }
};
