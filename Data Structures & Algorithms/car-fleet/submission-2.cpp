class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // i use monotonic stack this time

        // create a vector with pairs for position and speed
        vector<pair<int, int>> vehicles(position.size());
        for (int i = 0; i < position.size(); i++) {
            vehicles[i] = {position[i], speed[i]};
        }
        // sort them in descending order based on position
        sort(vehicles.begin(), vehicles.end(), greater<pair<int, int>>());

        stack<pair<int, int>> s;
        // if eta is > top of stack, add to it
        for (int i = 0; i < vehicles.size(); i++) {
            float eta = (float) (target - vehicles[i].first) / vehicles[i].second;
            if (s.empty() || eta > (float) (target - s.top().first) / s.top().second) s.push(vehicles[i]);
        }

        return s.size();
        // return size of stack
    }
};
