#include <vector>


class Solution {
public:
    using Pos = std::pair<int,int>;
    static constexpr std::array<Pos, 4> dirs {{
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1},
    }};
    
    // process island
    using Grid = vector<vector<char>>;
    bool is_land(Pos start, const Grid& grid) {
       auto [row, col] = start;
       if (row < 0 || row >= grid.size()) return false;
       if (col < 0 || col >= grid[0].size()) return false;
       if (grid[row][col] != '1') return false;
       return true;
    }
    bool find_island(Pos start, Grid& grid) {
        if (!is_land(start, grid)) return false;
        auto [row, col] = start;
        
        std::queue<Pos> wavefront;
        grid[row][col] = '2';
        wavefront.push(start);
        
        while (!wavefront.empty()) {
            auto [row, col] = wavefront.front();
            wavefront.pop();
            
            for (auto [dr, dc] : dirs) {
                auto nr = row + dr;
                auto nc = col + dc;
                Pos new_pos{nr, nc};

                if (is_land(new_pos, grid)) {
                    grid[nr][nc] = '2';
                    wavefront.push(new_pos);
                }
            }
        }
        return true;
    }
    int numIslands(vector<vector<char>>& grid) {
        int island_count = 0;
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (find_island({row, col}, grid)) {
                    ++island_count;
                }
            }
        }
        return island_count;
    }
};
