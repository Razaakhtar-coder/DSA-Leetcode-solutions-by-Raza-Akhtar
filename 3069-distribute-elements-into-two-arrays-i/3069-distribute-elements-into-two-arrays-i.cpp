class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for (int i = 2; i < nums.size(); i++) { // index 0 & 1 are already handled so start from index 2
            if (arr1.back() > arr2.back()) { // arr1.back or arr2.back gives us the last elements
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }

        vector<int> ans = arr1;
        ans.insert(ans.end(), arr2.begin(), arr2.end()); //Insert everything from arr2 at the end of ans.

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna