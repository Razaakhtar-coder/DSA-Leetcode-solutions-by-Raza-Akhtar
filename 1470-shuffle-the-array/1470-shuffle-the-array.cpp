class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) { // t.c - 0(n), s.c - 0(n)
        vector<int> ans;

        for(int i=0; i<n; i++){
            ans.push_back(nums[i]); // for first half of array
            ans.push_back(nums[i+n]); // for second half of array
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna