class Solution {
public:
    void backtrack(vector<int>& nums, int index,
                   vector<int>& current,
                   vector<vector<int>>& result) {
        
        result.push_back(current);

        for(int i = index; i < nums.size(); i++) {
            if(i > index && nums[i] == nums[i-1]) continue;
 // skip duplicates
            
            current.push_back(nums[i]);
            backtrack(nums, i + 1, current, result);
            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, 0, current, result);
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna