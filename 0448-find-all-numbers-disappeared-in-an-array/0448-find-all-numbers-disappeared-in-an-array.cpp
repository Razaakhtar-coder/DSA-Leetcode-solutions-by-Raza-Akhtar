class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();

        // Mark numbers that exist
        for (int num : nums) {
            int idx = abs(num) - 1; // substract 1 from the number's idx to get the original number
            nums[idx] = -abs(nums[idx]); // convert it to negative after going to the number
        }

        // Positive positions represent missing numbers
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) { // check if we have already taken the number
                ans.push_back(i + 1); // push ans
            }
        }

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
