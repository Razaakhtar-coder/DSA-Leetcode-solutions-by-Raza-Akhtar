class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) { // t.c- 0(n), s.c- 0(1)
        int count = 0;
        int index; // index tells us which value to check.

        if(ruleKey == "type"){
            index = 0;
        }
        else if(ruleKey == "color"){
            index = 1;
        }
        else{
            index = 2;
        }

        for(int i=0; i<items.size(); i++){
            if(items[i][index] == ruleValue){ // 1 ->i = 0: items[0][1] is "blue". It doesn't match "silver". 2->i = 1: items[1][1] is "silver". It matches, so count becomes 1. 3->i = 2: items[2][1] is "gold". It doesn't match.
                count++;
            }
        }
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna