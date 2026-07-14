class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // if top of stack is greater than current, calculate its area and max it with currentMax
            // area = (currentIdx - startIdx) * height[startIdx]
            // push current to top of stack with its startIdx set to the one you popped's startIdx
        // if top of stack is less than or equal to current, push
        // after all is done, any heights still in the stack mean they lasted until the end. find their area and max them out

        stack<pair<int, int>> s;
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (s.empty() || s.top().first <= heights[i]) {
                s.push({heights[i], i});
            } else {
                int startIdx;
                while (!s.empty() && s.top().first > heights[i]) {
                    startIdx = s.top().second;
                    int area = (i - startIdx) * s.top().first;
                    maxArea = max(maxArea, area);

                    s.pop();
                }

                s.push({heights[i], startIdx});
            }
        } 

        while (!s.empty()) {
            int area = (heights.size() - s.top().second) * s.top().first;
            maxArea = max(maxArea, area);

            s.pop();
        }

        return maxArea;
    }
};
