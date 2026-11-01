// #include <print>
#include <ranges>
class Solution {
public:
    static constexpr auto inf = std::numeric_limits<int>::max();
    struct Edge {
        int to{0};
        int weight{inf};
    };
    using Adj = std::vector<std::vector<Edge>>;
    static Adj make_adj(const auto num_nodes, vector<vector<int>> edges) {
        Adj adj(num_nodes + 1);
        for (const auto& edge: edges) {
            auto src = edge[0];
            auto dst = edge[1];
            auto weight = edge[2];
            adj[src].push_back({.to = dst, .weight = weight});
        }
        return adj;
    }

    struct Compare {
      bool operator()(const Edge& e1, const Edge& e2) const {
        return e1.weight > e2.weight;
      }
    };
    using Wavefront = std::priority_queue<Edge, std::vector<Edge>, Compare>;
    int dijkstras(int start, const auto num_nodes, const Adj& neighbors) {
        std::vector<int> distances(num_nodes + 1, inf);
        // dummy node
        distances[0] = 0;
        distances[start] = 0;
        Wavefront wv;
        wv.push(Edge{start, 0});

        while (!wv.empty()) {
            auto curr = wv.top();
            wv.pop();
            auto [node, cost] = curr;
            // std::println("try proc node {} cost {}", node, cost);

            // if we already found a better path
            // to node, skip edge
            if (cost > distances[node]) {
                continue;
            }
            

            for (const auto [n, weight] : neighbors[node]) {
                // overflow check
                if (cost > inf - weight) {
                    continue;
                }
                auto candidate_cost = cost+weight;
                // relax
                // std::println("candiate cost from {} to {} is {}", node,n, candidate_cost);
                // std::println("prev distance {}", distances[n]);
                if (candidate_cost < distances[n]) {
                    wv.push({n, candidate_cost});
                    distances[n] = candidate_cost;
                }
            }
        }
        
        // std::println("distances at end of dijk");
        // for (int i = 0; i < distances.size(); i++) {
        //     std::print("{}, ", distances[i]);
        // }
        // std::println("");
        return *std::ranges::max_element(distances);
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        auto neighbors = make_adj(n,times);
        // std::println("neighbors");
        // for (auto [idx,ns] : neighbors | std::views::enumerate) {
        //     std::println("neighbors for node {}", idx);
        //     for (auto n : ns) {
        //         std::print("to {} w {}, ", n.to, n.weight);
        //     }
        //     std::println("");
        // }
        int slowest_time = dijkstras(k, n, neighbors);
        return slowest_time == inf ? -1 : slowest_time;
    }
};

// indexes base 1 
// ti is the path cost
// graph is static so there should be no counts to inf
