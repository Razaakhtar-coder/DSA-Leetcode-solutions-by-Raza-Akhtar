class Solution {
public:
    int solve(vector<int>& nums, int start, int end){
        int n = nums.size();
        if(n == 1)
        return nums[0]; // if there is only one house

        vector<int> dp(n-1);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);

        for(int i=start+2, j=2; i<=end; i++, j++){ // i for tracking nums array and j for tracking dp array
            dp[j] = max(dp[j-1], dp[j-2] + nums[i]);
        }
        return dp[n-2];
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1)
        return nums[0];

        if(nums.size() == 2)
        return max(nums[0], nums[1]);
       
     return max(solve(nums, 0, nums.size()-2), solve(nums, 1, nums.size()-1));
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna