class Solution {
public:
    bool solve(string s, string p){
        if(p.size() == 0){
            return s.size() == 0;
        }

        bool firstCharMatch = false;
        if(s.size() > 0 && (p[0] == s[0] || p[0] == '.')){
            firstCharMatch = true;
        }

        if(p[1] == '*'){
            bool notTake = solve(s, p.substr(2));
            bool take = firstCharMatch && solve(s.substr(1), p);

            return notTake || take;
        }

            else{
                return firstCharMatch && solve(s.substr(1), p.substr(1));
            }
        
    }

    bool isMatch(string s, string p) {
        return solve(s, p);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna