
class Solution {
public:
    int calPoints(vector<string>& operations) { // t.c - 0(2n) i.e 0(n), s.c - 0(n)
        vector<int> scores;

        for (string op : operations) {
            if (op == "C") { // invalidate and remove previous record
                scores.pop_back();
            }
            else if (op == "D") { // multiply previous record with current
                scores.push_back(2 * scores.back());
            }
            else if (op == "+") { // add records
                int last = scores.back();
                int secondLast = scores[scores.size() - 2];

                scores.push_back(last + secondLast);
            }
            else {
                scores.push_back(stoi(op)); // stoi -> Convert a string to an integer
            }
        }

        int total = 0;

        for (int score : scores) {
            total += score; // return total records
        }

        return total;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna