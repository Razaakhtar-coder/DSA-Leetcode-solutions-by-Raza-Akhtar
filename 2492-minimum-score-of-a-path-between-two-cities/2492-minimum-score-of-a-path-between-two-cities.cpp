class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto &r : roads) {
            int u = r[0], v = r[1], d = r[2]; //u = starting city
//v = ending city
//d = distance
            adj[u].push_back({v, d}); 
            adj[v].push_back({u, d});
        }

        vector<bool> vis(n + 1, false);
        queue<int> q;
        q.push(1); // start BFS from first city
        vis[1] = true; // mark first city as true

        int ans = INT_MAX; //Return the minimum possible score of a path between cities 1 and n.

        while (!q.empty()) {
            int u = q.front(); // take front city 
            q.pop(); // remove front city

           for(auto &[v, d] : adj[u]){
            ans = min(ans, d);
                
           
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
           }
            
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna