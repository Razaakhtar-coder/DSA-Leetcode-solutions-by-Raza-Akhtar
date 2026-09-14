class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0); // t.c - 0(n*n), s.c - 0(n)

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                    if(nums[j] < nums[i])
                    ans[i]++;
                
            }
            
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna