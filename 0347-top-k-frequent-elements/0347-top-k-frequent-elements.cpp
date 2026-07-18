class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        // Count frequencies
        for (int num : nums) {
            mp[num]++;
        }

       vector<vector<int>> bucket(nums.size() + 1);

       for(auto &it: mp){
        bucket[it.second].push_back(it.first);
       }

       vector<int> ans;

       for(int i=nums.size(); i>=1; i--){
       for(auto num: bucket[i]){
          ans.push_back(num);
          if(ans.size() == k) return ans;
       }
       }
       return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna