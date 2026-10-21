class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) { // t.c - 0(n), s.c - 0(1)
           long long xor_r = 0;

           for(int &num : nums){
            xor_r ^= num; // take xor of every element
           }

           // mask -> right most set bit search
           int mask = (xor_r) & (-xor_r); // formula for finding mask

           int groupa = 0; // make groupa for first bit set
           int groupb = 0; // make groupb for not first bit set

           for(int &num : nums){
            if(num & mask){
                groupa ^= num; // if first bit set than number goes in groupa
            }
            else{
                groupb ^= num; // // if not first bit set than number goes in groupb
            }
           }
           return{groupa, groupb};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna