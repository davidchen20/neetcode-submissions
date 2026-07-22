class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;

        int left = 0;
        int right = left + 1;

        int maxProfit = 0;

        while (right < prices.size()) {
            if (prices[right] < prices[left]) {
                left = right;
                right++;
            } else {
                maxProfit = max(maxProfit, prices[right] - prices[left]);
                right++;
            }
        }

        return maxProfit;
    }
};
