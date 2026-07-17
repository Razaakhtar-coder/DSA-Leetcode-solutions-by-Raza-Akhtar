class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        int ans = n; //Look carefully Inside the loop we XOR 0 1 2 But 3 never appears as an index.Indices are 0 1 2So we manually include 3 first.

        for(int i=0; i<n; i++){ // loop runs for i=0, i=1, i=2
            ans ^= i; //ans = 3 ^ 0, hence ans = 3
            ans ^= nums[i]; //nums[0]=3, so ans = 3 ^ 3= 0 than 0^1= 1 and 1^2 gives 3 so we have aur answer now 3^1 = 2 -> ans.
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
