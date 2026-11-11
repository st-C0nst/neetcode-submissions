constexpr std::array<std::pair<int,int>, 4> dirs {{
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
}};
class Solution {
public:
    using Grid = vector<vector<int>>;
    static bool in_bounds(int row, int col, const Grid& grid) {
        if (row < 0 || row >= grid.size()) return false;
        if (col < 0 || col >= grid[0].size()) return false;
        return true;
    }
    static bool is_valid_land(int row, int col, const Grid& grid) {
        return in_bounds(row, col, grid) && grid[row][col] == 1;
    }
    using Wavefront = std::queue<std::pair<int,int>>;
    static int find_area(int row, int col, Grid& grid) {
        int curr_area = 0;
        Wavefront wv;
        wv.push({row, col});

        while (!wv.empty()) {
            auto [r, c] = wv.front();
            wv.pop();
            if (!is_valid_land(r,c,grid)) {
                continue;
            }
            grid[r][c] = -1;
            ++curr_area;

            // add neighbors
            for (const auto [dr, dc] : dirs) {
                auto nr = r + dr;
                auto nc = c + dc;
                wv.push({nr, nc});
            }
        }
        return curr_area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        const auto n = grid.size();
        const auto m = grid[0].size();
        auto max_area{0};
        
        for (int row{0}; row < n; ++row) {
            for (int col{0}; col < m; ++col) {
                if (grid[row][col] == 1) {
                    max_area = std::max(max_area, find_area(row, col, grid));
                }
            }
        }
        return max_area;
    }
};

// lets try bfs
