class Solution {
public:
   void solve(string digit, string output, int idx, vector<string>& ans, string mapping[]){
    // base case
    if(idx >= digit.size()){
        ans.push_back(output);
        return;
    }
    int num = digit[idx] - '0';
    string value = mapping[num];

    for(int i=0; i<value.size(); i++){
        output.push_back(value[i]);
        solve(digit, output, idx + 1, ans, mapping);
        output.pop_back();
    }
   }
    

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0) return ans;
        string output;
        int idx = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, output, idx, ans, mapping);
        return ans;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna