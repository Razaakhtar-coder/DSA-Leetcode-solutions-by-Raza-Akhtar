class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> st;

    for (int ast : asteroids) {
        bool destroyed = false;

        while (!st.empty() && ast < 0 && st.back() > 0) { //ast moving on left and top of stack is moving to right
            if (abs(st.back()) < abs(ast)) {
                st.pop_back(); // stack asteroid destroyed
                continue;
            } else if (abs(st.back()) == abs(ast)) {
                st.pop_back(); // both destroyed
            }
            destroyed = true;
            break;
        }

        if (!destroyed) {
            st.push_back(ast);
        }
    }

    return st;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna