// class Solution {
// public:
//      int n;
//      int dp[100001];

//      int solve(int i, vector<int>& prefixSum){
//         if(i == n-1){
//             return prefixSum[n-1];
//         }
//         if(dp[i] != -1){
//             return dp[i];
//         }
//         int take = prefixSum[i] - solve(i+1, prefixSum);
//         int skip = solve(i+1, prefixSum);

//         return dp[i] = max(take, skip); //we are returning max because they both want to increase there score so alice score++ and -bob score++.
//      }

//     int stoneGameVIII(vector<int>& stones) {
//         n = stones.size();
//         memset(dp, -1, sizeof(dp));

//         vector<int> prefixSum(n, 0);
//         prefixSum[0] = stones[0];

//         for(int i=1; i<n; i++){
//             prefixSum[i] = prefixSum[i-1] + stones[i];
//         }

//         return solve(1, prefixSum); // as given in question x > 1 and alice starts first
//     }
// };

//Approach-2 - Bottom Up
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<int> prefixSum(n, 0);
        prefixSum[0] = stones[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + stones[i];
        }

        vector<int> t(n);
        t[n - 1] = prefixSum[n - 1];                       // base case: solve(n-1)
        
        for (int i = n - 2; i >= 1; i--) {
            int take = prefixSum[i] - t[i + 1];
            int skip = t[i+1];

            t[i] = max(take, skip);
        }

        return t[1]; // == solve(1)
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna