class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) { // t.c - 0(n+k), s.c - 0(1)
        int maxNum = *max_element(nums.begin(), nums.end()); // sort by max element

        int sum = 0;

        for (int i = 0; i < k; i++) {
            sum += maxNum;
            maxNum++;
        }

        return sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna