class Solution {
public:
     int dp[501][501];

   int solve(int i, int j, vector<int>& piles){

    if(i > j) 
    return 0;

    if(i == j)
    return piles[i];

    if(dp[i][j] != -1)
    return dp[i][j];

    int takeI = piles[i] + min(solve(i+2, j, piles), solve(i+1, j-1, piles)); //t.c -> 0(2^n)

    int takeJ = piles[j] + min(solve(i+1, j-1, piles), solve(i, j-2, piles)); // return minimum from takeI and takeJ

    return dp[i][j] = max(takeI, takeJ); // return max of both
   }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memset(dp, -1, sizeof(dp));

        int totalScore = accumulate(piles.begin(), piles.end(), 0);
        int aliceScore = solve(0, n-1, piles);
        int bobScore = totalScore - aliceScore;

        if(aliceScore > bobScore){
            return true;
        }
        else{
            return false;
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna