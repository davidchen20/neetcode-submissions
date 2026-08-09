class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());

        // for (int i = 0; i < stones.size(); i++) {
        //     pq.push(stones[i]);
        // }

        while (pq.size() > 1) {
            int s1 = pq.top();
            pq.pop();

            // if (pq.empty()) break;

            int s2 = pq.top();
            pq.pop();

            if (s1 == s2) continue;
            else pq.push(abs(s1 - s2));
        }

        return pq.empty() ? 0 : pq.top();
    }
};
