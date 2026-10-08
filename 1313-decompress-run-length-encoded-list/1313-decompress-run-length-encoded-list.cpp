class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;

        for (int i = 0; i < nums.size(); i += 2) {
            int frequency = nums[i];
            int value = nums[i + 1];

            for (int j = 0; j < frequency; j++) {
                ans.push_back(value);
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna