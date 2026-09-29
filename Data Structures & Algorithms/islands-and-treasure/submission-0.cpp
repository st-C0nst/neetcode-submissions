#include <vector>
#include <limits>
#include <queue>

using namespace std;

using Pos = pair<int, int>;

class Solution {
 public:
  const array<int, 5> dirs{-1, 0, 1, 0, -1};
  void islandsAndTreasure(vector<vector<int>>& grid) {
    const int inf = numeric_limits<int>::max();
    queue<Pos> wv;

    for (int row = 0; row < grid.size(); ++row) {
      for (int col = 0; col < grid[0].size(); ++col) {
        if (grid[row][col] == 0) {
          wv.push({row, col});
        }
      }
    }

    int stepCount = 0;
    while (!wv.empty()) {
      ++stepCount;
      for (int i = wv.size(); i > 0; --i) {
        auto& [row, col] = wv.front();
        wv.pop();
        
        for (int d = 0; d < 4; ++d) {
          int newRow = row + dirs[d];
          int newCol = col + dirs[d + 1];

          if (newRow >= 0 && newCol >= 0 && newRow < grid.size() && newCol < grid[0].size() && grid[newRow][newCol] == inf) {
            grid[newRow][newCol] = stepCount;
            wv.push({newRow, newCol});
          }
        }
      }
    }
  }
};
