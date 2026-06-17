class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;

        int m = 0;

        while (left < right) {
            int area = min(heights[left], heights[right]) * (right - left);

            m = max(m, area);

            if (heights[left] < heights[right]) left++;
            else right--;
        }

        return m;
    }
};
