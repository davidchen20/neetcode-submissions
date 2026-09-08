class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> s;
        vector<int> ans(temperatures.size());

        for (int i = 0; i < temperatures.size(); i++) {

            while (!s.empty() && temperatures[i] > s.top().first) {
                int diff = i - s.top().second;
                ans[s.top().second] = diff;

                s.pop();
            }

            s.push({temperatures[i], i});
        }

        return ans;
    }
};
