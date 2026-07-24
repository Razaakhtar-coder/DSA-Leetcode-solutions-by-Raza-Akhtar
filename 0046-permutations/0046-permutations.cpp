class Solution {
public:
    void getPermutation(vector<int>& nums, int index, vector<vector<int>>& result) {

        if (index == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++) {

            swap(nums[index], nums[i]);

            getPermutation(nums, index + 1, result);

            swap(nums[index], nums[i]); // backtrack
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> result;

        getPermutation(nums, 0, result);

        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna