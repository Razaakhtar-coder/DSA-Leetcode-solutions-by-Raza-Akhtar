class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        // Case 1: k == 1 // if every element appears only once in subarray
        if (k == 1) {
            int ans = -1;

            for (auto& [num, count] : freq) {
                if (count == 1) {
                    ans = max(ans, num);
                }
            }

            return ans;
        }

        // Case 2: k == n
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        // Case 3: 1 < k < n
        int ans = -1;

        if (freq[nums[0]] == 1) { // check the firt element if it had occured only once
            ans = max(ans, nums[0]);
        }

        if (freq[nums[n - 1]] == 1) { // check the last element if it had occured only once
            ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna