class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n); // create ans vector with size n, otherwise we will get a runtime error

        for(int i=0; i<n; i++){
           ans[i] = nums[nums[i]]; // formula to calculate zero-based permutation, given in question itself
        }
        return ans;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna