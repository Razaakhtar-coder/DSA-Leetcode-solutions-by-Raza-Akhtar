class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) // if there is only 1 house
        return nums[0];

        vector<int> dp(n+1);

        dp[0] = nums[0]; // 1 house initialize with 0
        dp[1] = max(nums[0], nums[1]); // 2 house , return max of them

        for(int i=2; i<n; i++){
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]); // loop into array and create ans in dp array
        }

        return dp[n-1];



    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna