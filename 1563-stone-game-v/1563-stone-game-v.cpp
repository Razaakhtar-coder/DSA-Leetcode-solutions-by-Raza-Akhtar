class Solution { // bottom up code
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> prefixSum(n, 0);
        prefixSum[0] = stoneValue[0];
        for(int i=1; i<n; i++){
            prefixSum[i] = prefixSum[i-1] + stoneValue[i];
        }
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int l= n-1; l>=0; l--){ // to find and fill the values of last elements we are using backword loop
            for(int r=l+1; r<n; r++){
                int score = 0;
                for(int mid=l; mid<=r-1; mid++){
                    int leftSum = prefixSum[mid] - (l-1 >= 0 ? prefixSum[l-1] : 0); // check if l is not out of boud, l to mid
                    int rightSum = prefixSum[r] - prefixSum[mid]; // mid+1 to r

                    if(leftSum < rightSum){
                        score = max(score, leftSum + dp[l][mid]);
                    }
                    else if(leftSum > rightSum){
                        score = max(score, rightSum + dp[mid+1][r]);
                    }
                    else{
                        score = max({score, leftSum + dp[l][mid], rightSum + dp[mid+1][r]});
                    }
                }
                dp[l][r] = score;

            }
        }
        return dp[0][n-1];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna