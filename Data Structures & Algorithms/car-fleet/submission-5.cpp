class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // push onto stack. last on stack is first one to make it. 
        // if one gets cock blocked by another/makes it at the same time, no need to push to stack again

        stack<int> s;

        vector<pair<int, int>> vehicles(position.size());

        for (int i = 0; i < vehicles.size(); i++) {
            vehicles[i] = { position[i], speed[i] };
        }

        sort(vehicles.begin(), vehicles.end(), greater<pair<int, int>>());

        for (int i = 0; i < position.size(); i++) {
            if (s.empty()) s.push(i);

            int frontCar = s.top();

            float frontETA = (float) (target - vehicles[frontCar].first) / vehicles[frontCar].second;

            float currentETA = (float) (target - vehicles[i].first) / vehicles[i].second;

            if (currentETA > frontETA) s.push(i);
        }

        return s.size();
    }
};
