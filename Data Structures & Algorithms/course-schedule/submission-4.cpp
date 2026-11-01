class Solution {
public:
    using Bool = std::uint8_t;
    using PathSet = std::vector<Bool>;
    using VisitedSet = std::vector<Bool>;
    using Adj = std::vector<vector<int>>;
    using Edges = vector<vector<int>>;
    static bool topological_search(int node,int& num_completed, const Adj& neighbors, PathSet& path_nodes, VisitedSet& visited) {
        // found a cycle
        if (path_nodes[node] == 1) {
            return false;
        }
        // already visited the node
        if (visited[node] == 1) {
            return true;
        }
        // add to path
        path_nodes[node] = 1;
        ++num_completed;

        // search neighbors
        for (const auto n : neighbors[node]) {
            if (!topological_search(n, num_completed, neighbors, path_nodes, visited)) {
                return false;
            }
        }

        // remove from path and mark visited
        path_nodes[node] = 0;
        visited[node] = 1;

        return true;
    }
    static Adj make_adj(const int num_nodes, const Edges& edges) {
        Adj adj(num_nodes);
        for (const auto& e : edges) {
            auto src = e[1];
            auto dst = e[0];
            adj[src].push_back(dst);
        }
        return adj;
    }
    
    bool canFinish(int numCourses, Edges& prerequisites) {
        PathSet path(numCourses);
        VisitedSet visited(numCourses);
        int num_completed = 0;
        auto neighbors = make_adj(numCourses, prerequisites);
        
        for (int node = 0; node < numCourses; ++node) {
            if (!topological_search(node, num_completed, neighbors, path, visited)) {
                return false;
            }
        }

        return num_completed == numCourses;
    }
};
