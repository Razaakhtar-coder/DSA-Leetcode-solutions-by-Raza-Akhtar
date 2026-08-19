class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> mp; // took unordered set in map beacause we have unique values as index

        for(auto &reservedSeat : reservedSeats){
            int row = reservedSeat[0];
            int seat = reservedSeat[1];

            mp[row].insert(seat); // map filled
        }

        int ans = (n - mp.size()) * 2; // n is no.of rows and substract mp.size() to see which rows are completely empty

        for(auto &[row, bookedSeats] : mp){

            auto isAvailable = [&](int seat){ // lambda function
                return bookedSeats.find(seat) == bookedSeats.end(); // is it available or not and we didnt find it and the seat is empty we can use it.
            };

            bool groupA = isAvailable(2) && isAvailable(3) && isAvailable(4) && isAvailable(5);
            bool groupB = isAvailable(4) && isAvailable(5) && isAvailable(6) && isAvailable(7);
            bool groupC = isAvailable(6) && isAvailable(7) && isAvailable(8) && isAvailable(9);

            if(groupA && groupC){

                ans += 2; // add 2 sets of four people group
            }
            else if
               (groupA || groupB || groupC){

                ans += 1;
               }

        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna