class Solution {
public:
    struct Comparator {
        bool operator()(const pair<int, int>& v1, const pair<int, int>& v2) {
            return v1.first < v2.first;
        }
    };
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // put vehicles in stack based on position
        // if time to destination is <= pack leader, its part of fleet
        // if it is greater, add to the fleet count
        priority_queue<pair<int,int>, vector<pair<int,int>>, Comparator> vehicles;

        for (int i = 0; i < position.size(); i++) {
            vehicles.push({position[i], i});
        }

        int fleetCount = 0;
        int fleetLeader = -1;
        while (!vehicles.empty()) {
            pair<int, int> voi = vehicles.top();
            vehicles.pop();

            if (fleetLeader < 0) {
                fleetLeader = voi.second;
                fleetCount++;
                continue;
            }

            float fleetLeaderETA = (float) (target - position[fleetLeader]) / speed[fleetLeader];
            float voiETA = (float) (target - position[voi.second]) / speed[voi.second];

            if (voiETA > fleetLeaderETA) {
                fleetCount++;
                fleetLeader = voi.second;
            }
        }

        return fleetCount;

    }
};
