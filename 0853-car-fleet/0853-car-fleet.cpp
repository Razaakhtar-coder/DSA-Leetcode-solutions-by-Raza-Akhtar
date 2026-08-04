class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int, double>> cars;

        for (int i = 0; i < n; i++) {   //t.c- 0(n log n), s.c- 0(n)
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        sort(cars.begin(), cars.end());

        int fleets = 0;
        double lastTime = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (cars[i].second > lastTime) {
                fleets++;
                lastTime = cars[i].second;
            }
        }

        return fleets;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna