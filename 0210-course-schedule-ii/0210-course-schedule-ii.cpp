class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph,
             vector<int>& vis, vector<int>& ans) {

        vis[node] = 1; // currently visiting

        for (int ngbr : graph[node]) {

            if (vis[ngbr] == 1)
                return true; // cycle found

            if (vis[ngbr] == 0) {
                if (dfs(ngbr, graph, vis, ans))
                    return true;
            }
        }

        vis[node] = 2; // completely processed
        ans.push_back(node);

        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses); // adjacecncy list

        for (auto &p : prerequisites) {
            graph[p[1]].push_back(p[0]);
        }

        vector<int> vis(numCourses, 0);
        vector<int> ans;

        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == 0) {
                if (dfs(i, graph, vis, ans))
                    return {};
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna