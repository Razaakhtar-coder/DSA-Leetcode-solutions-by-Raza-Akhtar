class Solution {
public:
    string restoreString(string s, vector<int>& indices) { // TC: O(n), SC: O(n)
        int n = s.size();
        string ans = s;

        for(int i=0; i<n; i++){
            ans[indices[i]] = s[i]; // Put s[i] at position indices[i]. ex - s[0] = 'c' → ans[4] = 'c', s[1] = 'o' → ans[5] = 'o', s[2] = 'd' → ans[6] = 'd'
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna