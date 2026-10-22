class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;

        for(int &num : arr){ 
            mp[num]++;
        }
        vector<int> freq;

        for(auto &it : mp){ // it.first - element, it.second - freq of element
          freq.push_back(it.second);
        }
        sort(freq.begin(), freq.end());

        for(int i=0; i<freq.size(); i++){
            k -= freq[i]; // remove elemrnt

            if(k < 0){ 
                return freq.size() - i;
            }
        }
        return 0; // no elements were left all got deleted
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna