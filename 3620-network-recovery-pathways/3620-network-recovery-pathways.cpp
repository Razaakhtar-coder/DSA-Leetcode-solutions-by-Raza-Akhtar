class Solution {
public:
    typedef long long ll;
    typedef pair<long long, int> P;

    bool check(int mid, int n, ll k, unordered_map<int, vector<vector<int>>>& adj){
        //result[i] = min cost path from source to ith node
        vector<ll> result(n, LLONG_MAX);

        //min-heap for dijstras algorithm
        priority_queue<P, vector<P>, greater<P>> pq; //defined int and long long above thats why used P

        result[0] = 0;
        pq.push({0,0});

        while(!pq.empty()){
            ll d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(d > k){ // not a valid path
                return false;
            }
            if(node == n-1){
                return true;
            }
            if(result[node] < d){  // already got a valid path
                continue;
            }
            for(auto &vec : adj[node]){
                int ngbr = vec[0];
                int cost = vec[1];

                if(cost < mid){
                    continue;
                }

                if(d + cost < result[ngbr]){
                    result[ngbr] = d + cost;
                    pq.push({d + cost, ngbr});
                }
            }
        }
        return false;
    }



    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        // adjancey list
        unordered_map<int, vector<vector<int>>> adj;
        int l = INT_MAX;
        int r = 0;

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];

            if(!online[u] || !online[v]){
                continue;
            }

            adj[u].push_back({v, cost});
            l = min(l, cost);
            r = max(r, cost);
        }

        int ans = -1;
        while(l <= r){
            int mid = l + (r-l) /2; // mid score

            if(check(mid, n, k, adj)){
                ans = mid;
                l = mid +1;
            }
                else{
                    r = mid - 1;
                }
            
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna