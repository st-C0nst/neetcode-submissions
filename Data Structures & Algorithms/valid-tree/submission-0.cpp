class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> visit(n);
        
        if (!dfs(0, -1, adj, visit)) {
            return false;
        }

        for (const auto& visited : visit) {
            if (visited == 0) {
                return false;
            }
        }
        return true;
    }

    bool dfs(int node, int prev, vector<vector<int>>& adj, vector<int>& visit) {
        if (visit[node] == 1) {
            return false;
        }

        visit[node] = 1;
        for (const auto& neighbor : adj[node]) {
            if (neighbor != prev && !dfs(neighbor, node, adj, visit)) {
                return false;
            }
        }

        return true;
    }
};
