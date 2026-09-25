class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<pair<int, int>> s;
        for (int i = 0; i < temperatures.size(); i++) {
            if (s.empty()) s.push({ temperatures[i], i });

            while (!s.empty() && temperatures[i] > s.top().first) {
                int val = s.top().first;
                int idx = s.top().second;

                ans[idx] = i - idx;
                s.pop();
            }

            s.push({temperatures[i], i});
        }

        return ans;
    }
};
