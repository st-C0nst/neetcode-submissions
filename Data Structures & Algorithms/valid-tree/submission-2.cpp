#include <vector>
#include <ranges>
using Size = std::size_t;
class DSU {
    public:
    DSU(const Size capacity) : sizes_(capacity, 1) {
        parents_ = std::views::iota(0, static_cast<int>(capacity)) | std::ranges::to<std::vector<int>>();
        num_components_ = capacity;
    }
    bool unite(int n1, int n2) {
        auto r1 = find(n1);
        auto r2 = find(n2);
        if (r1 == r2) return false;
        auto size1 = sizes_[r1];
        auto size2 = sizes_[r2];
        if (size1 < size2) {
            std::swap(r1, r2);
            std::swap(size1, size2);
        }

        parents_[r2] = r1;
        sizes_[r1] += size2;
        --num_components_;
        return true;
    }

    int find(int node) {
        while (node != parents_[node]) {
            parents_[node] = parents_[parents_[node]];
            node = parents_[node];
        }

        return parents_[node];
    }
    [[nodiscard]]
    int num_sets() const {
        return num_components_;
    }
    
    private:
    std::vector<int> parents_;
    std::vector<int> sizes_;
    int num_components_{0};
};
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        DSU sets(n);
        for (const auto& edge : edges) {
            auto u = edge[0];
            auto v = edge[1];
            if (!sets.unite(u,v)) {
                return false;
            }
        }
        return sets.num_sets() == 1;
    }
};

// we could do a union find
// for every edge try to join to 

// you could also do a dfs