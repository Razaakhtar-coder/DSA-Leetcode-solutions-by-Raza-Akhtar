
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) { // t.c - 0(n), same s.c
        int n = nums.size();
        int totalSum = 0;
        int leftSum = 0;

        vector<int> ans;

        for (int x : nums) {
            totalSum += x; // add total sum
        }

        for (int i = 0; i < n; i++) {
            int rightSum = totalSum - leftSum - nums[i]; // at idx 0 - total=25,leftsum=0,currentsum=10, so rightsum = 15

            ans.push_back(abs(leftSum - rightSum)); // push absolute value of it

            leftSum += nums[i]; // This adds the current element to the left sum so that the next iteration has the correct left-side total
        }

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna