class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<bool>& visited,
             int src, int des) {

        if(src == des) {
            return true;
        }

        visited[src] = true;

        for(int neighbor : adj[src]) {
            if(!visited[neighbor]) {
                if(dfs(adj, visited, neighbor, des)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges,
                   int source, int destination) {

        vector<vector<int>> adj(n);

        // Build adjacency list for an undirected graph
        for(auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);

        return dfs(adj, visited, source, destination);
    }
};