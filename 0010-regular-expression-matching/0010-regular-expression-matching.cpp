class Solution {
public:
    bool solve(string s, string p){
        if(p.size() == 0){  // if pattern equals to 0
            return s.size() == 0;
        }

        bool firstCharMatch = false; // mark it as false
        if(s.size() > 0 && (p[0] == s[0] || p[0] == '.')){ // matching the first char of both string
            firstCharMatch = true; // make it true
        }

        if(p[1] == '*'){
            bool notTake = solve(s, p.substr(2)); // do not take * in this case, if we not take we directly move to 2 idx of the pattern
            bool take = firstCharMatch && solve(s.substr(1), p); // take * in this case, match the char from the first

            return notTake || take; // return either of them
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