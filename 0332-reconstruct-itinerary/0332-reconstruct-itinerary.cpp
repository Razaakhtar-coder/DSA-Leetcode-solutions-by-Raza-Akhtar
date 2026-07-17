class Solution { // used Hierholzer's Algorithm so that to avoid Time limit exceed
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
  // this is the main dfs code for this problem but gave TLE on leetcode

class Solution {
public:
    unordered_map<string, vector<string>> adj;
    vector<string> route;
    int numTickets = 0;
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
		numTickets = tickets.size();
        
		for (auto& t : tickets) {
            string u = t[0];
            string v = t[1];
            
			adj[u].push_back(v);
		}
        
        // Sort vertices in the adjacency list by lexical order
        for (auto &edges : adj) {
            sort(begin(edges.second), end(edges.second));
        }
        
        vector<string> temp;
        DFS("JFK", temp);
        return route;
    }
    
    bool DFS(string fromAirport, vector<string>& temp) {
        temp.push_back(fromAirport);
        
        // we have used all tickets, this is a valid path return the result
        if (temp.size() == numTickets+1) {
            route = temp;
            return true;
        }
        
        //You have already found the route (first valid lexicographically path)

        
        vector<string>& neighbors = adj[fromAirport];
        
        // at the current layer, try its neighbors in the sorted order
        for(int i = 0; i < neighbors.size(); i++) {
            
            string toAirport = neighbors[i];
            
            // remove ticket(route) from graph so that it won't be reused 
            neighbors.erase(neighbors.begin()+i);
            
            if(DFS(toAirport, temp))
                return true;
            
            // if the current path is invalid, restore the current ticket
            neighbors.insert(neighbors.begin()+i, toAirport);            
        }
        
        temp.pop_back();
        return false;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
