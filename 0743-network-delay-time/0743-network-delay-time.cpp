class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;

        for(auto &vec : times){
    int u = vec[0];
    int v = vec[1];
    int w = vec[2];

    adj[u].push_back({v, w});
        }

           priority_queue<pair<int,int>,
               vector<pair<int,int>>,
               greater<pair<int,int>>> minh;
               vector<int> result(n+1, INT_MAX);
               result[k] = 0;
               minh.push({0, k});
        
        
            while(!minh.empty()){
                int d = minh.top().first;
                int node = minh.top().second;
                minh.pop();

                for(auto &vec : adj[node]){
                    int adjNode = vec.first;
                    int dist = vec.second;

                    if(d + dist < result[adjNode]){
                        result[adjNode] = d + dist;
                    minh.push({d + dist, adjNode});
                    }
                }
            }
            int ans = INT_MIN;
            for(int i=1; i<=n; i++){
                ans = max(ans, result[i]);
            }
            return ans == INT_MAX ? -1: ans;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna