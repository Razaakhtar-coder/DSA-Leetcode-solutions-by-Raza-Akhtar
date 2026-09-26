class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size(); //t.c - 0(n), s.c - 0(n)
        vector<int> ans;

        for (int i = 0; i < 2 * n; i++) {
            ans.push_back(nums[i % n]); // i % n gives the exact same array nums ex- i       i % n       nums[i % n]
// 0          0             1
// 1          1             2
// 2          2             3
// 3          0             1
// 4          1             2
// 5          2             3
        }

        return ans;
    }
};

// class Solution {
// public:
//     vector<int> getConcatenation(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans;

//         for(int i=0; i<n; i++){
//            ans.push_back(nums[i]);
//         }

//         for(int i=0; i<n; i++){
//             ans.push_back(nums[i]);
//         }

//         return ans;
//     }
// };

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna