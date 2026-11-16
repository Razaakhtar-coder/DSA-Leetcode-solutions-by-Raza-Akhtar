class Solution {
public:
      long long maxTaxiEarnings(int n, vector<vector<int>>& rides) { // t.c - 0(mlogm), s.c - 0(m)- DP space

        sort(rides.begin(), rides.end(), [](const vector<int>& a, const vector<int>& b){ // sort the rides by its ending position and not starting position
            return a[1] < b[1];
        });

        int m = rides.size(); // storing the ending position

        vector<int> ends(m);

        for(int i=0; i<m; i++){
            ends[i] = rides[i][1];
        }

        vector<long long> dp(m+1, 0);

        for(int i=1; i<=m; i++){
          int start = rides[i-1][0];
          int end = rides[i-1][1];
          int tip = rides[i-1][2];

                      // Find number of rides ending <= start
            int j = upper_bound(
                ends.begin(),
                ends.begin() + (i - 1),
                start
            ) - ends.begin();

            // Option 1: Skip current ride
            long long skip = dp[i - 1];

            // Option 2: Take current ride
            long long take = dp[j] + (end - start + tip);

            dp[i] = max(skip, take);
        }
          return dp[m];
        }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna