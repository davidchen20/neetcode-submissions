class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> ans(temperatures.size());

        for (int i = 0; i < temperatures.size(); i++) {

            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                int diff = i - s.top();
                ans[s.top()] = diff;

                s.pop();
            }

            s.push(i);
        }

        return ans;
    }
};
