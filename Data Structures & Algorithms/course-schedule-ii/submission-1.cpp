#include <queue>
#include <ranges>
class Solution {
public:
    using Order = std::vector<int>;
    using Adj = std::vector<std::vector<int>>;
    using InDeg = std::vector<int>;
    using Edges = vector<vector<int>>;
    static std::pair<Adj, InDeg> make_dep(const int num_nodes, Edges& edges) {
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
    static Order kahns(const Adj& neighbors, InDeg& in_deg) {
        Order order;
        order.reserve(in_deg.size());

        auto wv = in_deg | std::views::enumerate | std::views::filter([](const auto item) {
            auto [_, n] = item;
            return n == 0;
        }) | std::views::keys | std::ranges::to<Wavefront>();

        while (!wv.empty()) {
            auto curr = wv.front();
            wv.pop();

            order.push_back(curr);

            for (const auto n : neighbors[curr]) {
                if (--in_deg[n] == 0) {
                    wv.push(n);
                }
            }
        }
        return order;
    }
    
    vector<int> findOrder(int numCourses, Edges& prerequisites) {
        auto [neighbors, in_deg] = make_dep(numCourses, prerequisites);

        auto order = kahns(neighbors, in_deg);

        if (order.size() != numCourses) {
            return {};
        }
        return order;
    }
};
