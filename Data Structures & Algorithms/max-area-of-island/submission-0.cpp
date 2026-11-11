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
    static int find_area(int row, int col, Grid& grid) {
        // if its out of bounds or if its water/visited, return 0
        if (!in_bounds(row,col,grid) || grid[row][col] != 1) {
            return 0;
        }
        // mark cell as visited
        grid[row][col] = -1;

        auto area = 1;
        for (const auto [drow, dcol] : dirs) {
            auto ne_row = drow + row;
            auto ne_col = dcol + col;
            area += find_area(ne_row, ne_col, grid);
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        const auto n = grid.size();
        const auto m = grid[0].size();
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < m; ++col) {
                if (grid[row][col] == 1) {
                    max_area = std::max(max_area,find_area(row, col, grid));
                }
            }
        }
        
        return max_area;
    }
};
