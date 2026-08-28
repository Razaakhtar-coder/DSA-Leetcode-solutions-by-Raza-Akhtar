//Approach (Greedy + backtracking)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    string result = "";

    bool solve(string& curr, vector<int>& count, string& target, int i, bool greater) {
        if(i == target.length()) { // base case if i reaches out of bound
            if(greater) {
                result = curr;
                return true;
            }
            return false;
        }

        for(char ch = 'a'; ch <= 'z'; ch++) {
            if(count[ch-'a'] == 0) // fill index
                continue;
            
            if(greater == false && ch < target[i]) // greater is still false continue
                continue;
            

            curr.push_back(ch);
            count[ch-'a']--; // backtrack from the character

            bool isGreater = greater || ch > target[i];

            if(solve(curr, count, target, i+1, isGreater)) {
                return true;
            }

            curr.pop_back();
            count[ch-'a']++; // add character when greater becomes true
        }

        return false;
    }

    string lexGreaterPermutation(string s, string target) {
        vector<int> count(26, 0);

        for(char &ch : s)
            count[ch-'a']++;
        
        string curr;

        solve(curr, count, target, 0, false);

        return result;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna