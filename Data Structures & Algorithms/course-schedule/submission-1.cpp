#include <queue>
#include <ranges>

class Solution {
public:
    using Edges = vector<vector<int>>;
    using Adj = std::vector<std::vector<int>>;
    using InDeg = std::vector<int>;

    static std::pair<Adj, InDeg> make_adj(const int num_nodes, Edges& edges) {
        Adj adj(num_nodes);
        InDeg deg(num_nodes);

        for (const auto& e : edges) {
            auto src = e[1];
            auto dst = e[0];
            adj[src].push_back(dst);
            ++deg[dst];
        }
        return {adj, deg};
        
    }
    using Wavefront = std::queue<int>;
    static std::vector<int> kahns(const Adj& neighbors, InDeg& in_deg) {
        auto wv = in_deg | std::views::enumerate | std::views::filter([](const auto item) {
            auto [idx, n] = item;
            return n == 0;
        }) | std::views::keys | std::ranges::to<Wavefront>();
        std::vector<int> order;

        while (!wv.empty()) {
            auto curr = wv.front();
            wv.pop();
            order.push_back(curr);

            for (const auto neighbor : neighbors[curr]) {
                if (--in_deg[neighbor] == 0) {
                    wv.push(neighbor);
                }
            }
        }
        return order;
    }
    bool canFinish(int numCourses, Edges& prerequisites) {
        auto [neighbors, in_deg] = make_adj(numCourses, prerequisites);
        auto order = kahns(neighbors, in_deg);

        if (order.size() != numCourses) {
            return false;
        }

        return true;
    }
};

// we should practice the BFS kahns algo + the dfs 