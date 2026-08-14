class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i = 0;
        int ans = 0;
        unordered_map<char, int> mp;

        for(int j=0; j<s.size(); j++){
            mp[s[j]]++;
        
        while(mp[s[j]] > 2){
            mp[s[i]]--;
            i++;
        }
        ans = max(ans, j-i+1);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna