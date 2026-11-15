class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) { // t.c - 0(n*k),where n is the number of words and k is the average word length. s.c - 0(1), auxilary space
        int n = words.size();
       
       vector<int> ans;

       for(int i=0; i<n; i++){
        if(words[i].find(x) != string::npos){ // find(x) searches for character x inside a word. string::npos means that word not found
            ans.push_back(i);
        }
       }
       return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna