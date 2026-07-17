class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> group(n, 0);
        int currGroup = 0;
        for(int i=1; i<n; i++){
            if(nums[i] - nums[i-1] > maxDiff)
                currGroup ++;  // i > maxdiff
                group[i] = currGroup; // if i !> maxdiff than assign the same number
            
        }
         // process queries : check if both nodes belong to the same group
         vector<bool> ans;
         for(auto &q: queries){
            int u = q[0], v = q[1];
            ans.push_back(group[u] == group[v]); // check if the groups are same return result
         }
         return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna