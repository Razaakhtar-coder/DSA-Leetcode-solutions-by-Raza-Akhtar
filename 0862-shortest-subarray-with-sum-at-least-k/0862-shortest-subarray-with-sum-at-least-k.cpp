class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {

        int n = nums.size();

        deque<pair<int,long long>> dq;

        long long sum = 0;

        int shortest = INT_MAX;

        for(int i = 0; i < n; i++) {

            sum += nums[i];

            // subarray from 0 to i
            if(sum >= k)
                shortest = min(shortest, i + 1);

            // remove valid prefixes
            while(!dq.empty() && sum - dq.front().second >= k) {

                shortest = min(shortest, i - dq.front().first);

                dq.pop_front();
            }

            // maintain increasing prefix sums
            while(!dq.empty() && sum <= dq.back().second)
                dq.pop_back();

            dq.push_back({i, sum});
        }

        return shortest == INT_MAX ? -1 : shortest;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna