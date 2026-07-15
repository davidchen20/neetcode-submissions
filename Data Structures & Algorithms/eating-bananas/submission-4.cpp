class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // right most boundary of what k could be is the max of piles
        // left most boundary of what k could be is 1

        // binary search (if current k takes too long, go to right)
        // if current k takes less time, go to left

        int maxPile = 0;
        for (int i = 0; i < piles.size(); i++) {
            maxPile = max(maxPile, piles[i]);
        }

        int left = 1;
        int right = maxPile + 1;

        int minK = maxPile;
        while (left < right) {
            int mid = left + (right - left) / 2;

            // calculate time to eat
            long time = 0;
            for (int i = 0; i < piles.size(); i++) {
                time += ceil(piles[i] / static_cast<double>(mid));
            }

            if (time > h) left = mid + 1;
            else {
                minK = min(mid, minK);
                right = mid;
            }
        }

        return minK;
    }
};
