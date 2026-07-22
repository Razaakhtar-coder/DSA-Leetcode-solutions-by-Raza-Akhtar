class Solution {
public:

    void solve(vector<int>& arr, int idx, int target,
               vector<int>& curr,
               vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(curr);
            return;
        }

       for (int i = idx; i < arr.size(); i++) {

            // Skip duplicates
            if (i > idx && arr[i] == arr[i - 1])
                continue;

            if (arr[i] > target)
                break;

            curr.push_back(arr[i]);

            // i+1 because one element can be used only once
            solve(arr, i + 1, target - arr[i], curr, ans);

            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {

        sort(arr.begin(), arr.end());

        vector<vector<int>> ans;
        vector<int> curr;

        solve(arr, 0, target, curr, ans);

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna