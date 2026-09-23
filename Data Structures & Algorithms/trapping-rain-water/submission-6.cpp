class Solution {
public:
    int trap(vector<int>& height) {
        // maxLeft[i] = maxHeight to the left of index i
        vector<int> maxLeft(height.size());
        for (int i = 1; i < maxLeft.size(); i++) {
            maxLeft[i] = max(maxLeft[i-1], height[i-1]);
        }

        vector<int> maxRight(height.size());
        for (int i = height.size() - 2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i+1], height[i+1]);
        }

        int trappedWater = 0;
        for (int i = 0; i < height.size(); i++) {
            int minHeight = min(maxLeft[i], maxRight[i]);

            if (height[i] <= minHeight) trappedWater += minHeight - height[i];
        }

        return trappedWater;
    }
};
