class Solution {
public:

    string encode(vector<string>& strs) {
        // put each word's size right before encoding
        string encoded = "";
        for (int i = 0; i < strs.size(); i++) {
            int size = strs[i].size();
            encoded += to_string(size) + "#" + strs[i];
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        for (int i = 0; i < s.size();) {
            // read until the #
            string size;
            while (s[i] != '#') {
                size.push_back(s[i]);
                i++;
            }

            i++;

            int intSize = std::stoi(size);

            string word;
            for (int j = 0; j < intSize; j++) {
                word.push_back(s[i]);
                i++;
            }

            ans.push_back(word);


        }

        return ans;
    }
};
