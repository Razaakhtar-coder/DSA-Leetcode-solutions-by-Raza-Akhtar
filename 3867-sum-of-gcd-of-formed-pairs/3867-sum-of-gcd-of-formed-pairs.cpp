class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n =  nums.size();
        int maxi = -1;

        vector<int> prefixgcd;
        for(int i=0; i<n; i++){
            maxi = max (maxi, nums[i]);
            prefixgcd.push_back(__gcd(nums[i], maxi)); 
        }
        sort(prefixgcd.begin(),prefixgcd.end());
        long long ans = 0;
        for(int i=0; i<n/2; i++){
            ans += __gcd(prefixgcd[i], prefixgcd[n-i-1]);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna