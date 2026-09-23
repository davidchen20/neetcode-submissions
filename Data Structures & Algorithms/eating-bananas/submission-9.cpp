class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxBanana = 0;
        for (int i = 0; i < piles.size(); i++) maxBanana = max(maxBanana, piles[i]);

        int minSpeed = INT_MAX;

        int left = 1; 
        int right = maxBanana;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            long long time = 0;
            for (int i = 0; i < piles.size(); i++) {
                time += ceil((double)piles[i] / mid);
            }

            if (time <= h) minSpeed = min(mid, minSpeed);

            if (time <= h) right = mid - 1;
            else left = mid + 1;
        }

        return minSpeed;
    }
};
