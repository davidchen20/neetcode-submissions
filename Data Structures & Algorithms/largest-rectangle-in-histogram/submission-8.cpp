class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> s;

        int maxArea = -1;
        for (int i = 0; i < heights.size(); i++) {
            if (s.empty() || s.top().first <= heights[i]) s.push({heights[i], i});
            else {
                int consideredHeight;
                int startIdx;
                while (!s.empty() && s.top().first > heights[i]) {
                    consideredHeight = s.top().first;
                    startIdx = s.top().second;
                    maxArea = max(maxArea, consideredHeight * (i - startIdx));
                    s.pop();
                }
                s.push({heights[i], startIdx});
            }
        }

        while (!s.empty()) {
            maxArea = max(maxArea, s.top().first * (int)(heights.size() - s.top().second));
            s.pop();
        }

        return maxArea;
    }
};
