class Solution {
public:
    vector<string> ans;

    void solve(string &s, int i){

        if(i == s.size()){ // reached the end
            ans.push_back(s);
            return;
        }

        if(isalpha(s[i])){ // if current char is letter

            s[i] = tolower(s[i]); // make it lowercase
            solve(s, i+1);

            s[i] = toupper(s[i]); // make it upper case
            solve(s, i+1);
        }
        else{
            solve(s, i+1); // if its a number than just move ahead
        }
    }

    vector<string> letterCasePermutation(string s) {
        solve(s, 0);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna