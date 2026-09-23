class Solution {
public:
    int trap(vector<int>& height) {
        int maxLeft = height[0];
        int maxRight = height[height.size() - 1];

        int left = 0;
        int right = height.size() - 1;

        int trappedWater = 0;
        while (left < right) {
            if (maxLeft <= maxRight) {
                left++;
                maxLeft = max(maxLeft, height[left]);
                trappedWater += max(0, maxLeft - height[left]);
                
            } else {
                right--;
                maxRight = max(maxRight, height[right]);
                trappedWater += max(0, maxRight - height[right]);
                
            }
        }

        return trappedWater;
    }
};
