class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // every car is bounded by the slowest car in front of it
        vector<pair<int, int>> cars(position.size());

        for (int i = 0; i < cars.size(); i++) {
            cars[i] = { position[i], speed[i] };
        }

        sort(cars.begin(), cars.end(), greater<pair<int, int>>());

        stack<double> etas;

        for (auto& car : cars) {
            double eta = (target - car.first) / (double) car.second;

            if (etas.empty() || eta > etas.top()) etas.push(eta);
        }

        return etas.size();
    }
};
