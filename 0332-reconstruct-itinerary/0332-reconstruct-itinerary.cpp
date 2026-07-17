class Solution {
public:
    unordered_map<string, multiset<string>> adj;
    vector<string> route;

    void dfs(string airport) {

        while (!adj[airport].empty()) {

            auto it = adj[airport].begin();   // smallest destination
            string next = *it;
            adj[airport].erase(it);           // use this ticket

            dfs(next);
        }

        // Add airport after all outgoing tickets are used
        route.push_back(airport);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {

        for (auto &t : tickets) {
            adj[t[0]].insert(t[1]);
        }

        dfs("JFK");

        reverse(route.begin(), route.end());

        return route;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna