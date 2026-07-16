class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n =  nums.size();
        int maxi = -1;

        vector<int> prefixgcd;
        for(int i=0; i<n; i++){
            maxi = max (maxi, nums[i]); //calculate max of prefixgcd
            prefixgcd.push_back(__gcd(nums[i], maxi)); // return max among the prefixgcd
        }
        sort(prefixgcd.begin(),prefixgcd.end()); // sort the max score we got from the above
        long long ans = 0;
        for(int i=0; i<n/2; i++){
            ans += __gcd(prefixgcd[i], prefixgcd[n-i-1]); // take gcd of smaller and larger element 
        }
        return ans; // return gcd of smaller and larger element ex-(2,3,6,8) -> (2,8), (3,6)
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna