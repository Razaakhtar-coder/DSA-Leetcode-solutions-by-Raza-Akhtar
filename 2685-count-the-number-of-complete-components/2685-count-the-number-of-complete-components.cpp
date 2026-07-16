class Solution {
public:
    void dfs(int node,
             unordered_map<int, vector<int>>& adj,vector<bool>& visited,int& vertices,int& edges) {

        visited[node] = true;
        vertices++;
        edges += adj[node].size();

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, vertices, edges);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> adj;

        // Build graph
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        int ans = 0;

        // Traverse every connected component
        for (int i = 0; i < n; i++) {

            if (visited[i])
                continue;

            int vertices = 0;
            int edgeCount = 0;

            dfs(i, adj, visited, vertices, edgeCount);

            // Every edge was counted twice
            edgeCount /= 2;

            // Complete graph should have V*(V-1)/2 edges
            if (edgeCount == vertices * (vertices - 1) / 2)
                ans++;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna