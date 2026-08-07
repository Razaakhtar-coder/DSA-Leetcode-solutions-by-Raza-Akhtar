class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {

        // {dp value, index}
        priority_queue<pair<int,int>> pq;

        int ans = nums[0];

        for (int i = 0; i < nums.size(); i++) {

            // remove out of range elements
            while (!pq.empty() && pq.top().second < i - k) {
                pq.pop();
            }

            int best = 0;

            if (!pq.empty()) {
                best = pq.top().first;
            }

            int curr = nums[i] + max(0, best);

            ans = max(ans, curr);

            pq.push({curr, i});
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna