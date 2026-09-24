class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counts;
        for (auto task : tasks) counts[task]++;

        priority_queue<int, vector<int>, less<int>> pq;

        for (auto& count : counts) {
            pq.push(count.second);
        }

        queue<pair<int, int>> availability;

        int time = 0;
        while (!pq.empty() || !availability.empty()) {
            if (!availability.empty()) {
                if (availability.front().second == time) {
                    pq.push(availability.front().first);
                    availability.pop();
                }
            }

            if (!pq.empty()) {
                int lettersLeft = pq.top();
                pq.pop();

                if (lettersLeft - 1 > 0) availability.push({lettersLeft - 1, time + n + 1});
            }

            time++;
        }

        return time;
    }
};
