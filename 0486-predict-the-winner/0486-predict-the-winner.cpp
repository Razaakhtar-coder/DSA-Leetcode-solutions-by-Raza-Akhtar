class Solution {
public:
// memoized version of dp.
  int dp[23][23];

   int solve(int i, int j, vector<int>& nums){

    if(i > j) 
    return 0;

    if(i == j)
    return nums[i];

    if(dp[i][j] != -1)
    return dp[i][j];

    int takeI = nums[i] + min(solve(i+2, j, nums), solve(i+1, j-1, nums)); //t.c -> 0(2^n)

    int takeJ = nums[j] + min(solve(i+1, j-1, nums), solve(i, j-2, nums)); // return minimum from takeI and takeJ

    return dp[i][j] = max(takeI, takeJ); // return max of both
   }

    bool predictTheWinner(vector<int>& nums) {
       int n = nums.size();
        memset(dp, -1, sizeof(dp));

       int totalScore = accumulate(nums.begin(), nums.end(), 0);

        int p1 = solve(0, n-1, nums);
        int p2 = totalScore - p1;

        return p1 >= p2;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna