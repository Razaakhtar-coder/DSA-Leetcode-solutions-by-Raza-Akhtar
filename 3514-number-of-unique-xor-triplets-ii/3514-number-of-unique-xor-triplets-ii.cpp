class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        // store all pairs of XORs
        unordered_set<int> s1;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                s1.insert(nums[i] ^ nums[j]);
            }
        }

        // find triplets XORs
        unordered_set<int> s2;
        for(auto pairXor : s1){
            for(auto &num : nums){
                s2.insert(pairXor ^ num);
            }
        }
        return s2.size();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna