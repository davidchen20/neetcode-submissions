class Solution {
public:
    int trap(vector<int>& height) {
        // calculate max height to left for all indices
        vector<int> maxLeft(height.size());
        int lastLeft = 0;
        for (int i = 0; i < height.size(); i++) {
            if (i == 0) {
                maxLeft[i] = 0;
                lastLeft = height[i];
                continue;
            }

            maxLeft[i] = max(lastLeft, maxLeft[i-1]);
            lastLeft = height[i];
        }
        
        // calculate max height to right for all indices
        vector<int> maxRight(height.size());
        int lastRight = 0;
        for (int i = height.size() - 1; i >= 0; i--) {
            if (i == height.size() - 1) {
                maxRight[i] = 0;
                lastRight = height[i];
                continue;
            }

            maxRight[i] = max(lastRight, maxRight[i+1]);
            lastRight = height[i];
        }

        // calculate total amount of water
        int ans = 0;

        for (int i = 0; i < height.size(); i++) {
            ans += max(0, min(maxLeft[i], maxRight[i]) - height[i]);
        }

        return ans;
    }
};
