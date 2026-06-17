class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> md;

        vector<int> result(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++) {
            if (md.empty()) {
                md.push({temperatures[i], i});
                continue;
            }

            int topElement = md.top().first;
            if (temperatures[i] < topElement) md.push({temperatures[i], i});
            else {
                while (!md.empty() && temperatures[i] > md.top().first) {
                    result[md.top().second] = i - md.top().second;
                    md.pop();
                }

                md.push({temperatures[i], i});
            }
        }

        return result;
    }
};
