class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) { // t.c - 0(1), same s.c
        int n = nums.size();

        if(n < 3){
            return -1; // more elements than 3, so no mid element....return -1
        }
         int a = nums[0], b = nums[1], c = nums[2];

        sort(nums.begin(), nums.begin() + 3);

        return nums[1];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna