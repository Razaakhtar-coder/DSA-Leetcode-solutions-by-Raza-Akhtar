class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        int n = intervals.size();

        auto lambda = [](const vector<int>& vec1, const vector<int>& vec2) {
            if (vec1[0] == vec2[0])
                return vec1[1] > vec2[1];   // larger end first
            return vec1[0] < vec2[0];       // smaller start first
        };

        sort(begin(intervals), end(intervals), lambda);

        result.push_back(intervals[0]);

        for (int i = 1; i < n; i++) {
            if (result.back()[1] >= intervals[i][1]) {
                continue;
            }
            result.push_back(intervals[i]);
        }

        return result.size();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna