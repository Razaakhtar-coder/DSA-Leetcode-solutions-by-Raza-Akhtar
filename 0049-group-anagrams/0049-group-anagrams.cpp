
class Solution {
    public :
     vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;

    for (string s : strs) {
        string key = s;
        sort(key.begin(), key.end());  // normalize "eat" → "aet","tea" → "aet"
        mp[key].push_back(s);
    }

    vector<vector<string>> result;
    for (auto& it : mp) {
        result.push_back(it.second);   //time complexity--> 0(n*k)
    }

    return result;
}
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna