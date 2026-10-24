#include <print>

using Index = int;

namespace nw {
inline Index diagonal_lookup(Index row, Index col, const int n) {
    return row - col + n - 1;
}
};


namespace ne {
inline Index diagonal_lookup(Index row, Index col) {
    return row + col;
}
};
class Solution {
public:
    using Bool = std::uint8_t;
    struct VisitSets {
        VisitSets(int n) : col_set(n), diag_nw(n*2 -1),diag_ne(n*2 + 1), size{n}{}
        std::vector<Bool> col_set;
        std::vector<Bool> diag_nw;
        std::vector<Bool> diag_ne;
        
        private:
            int size;
    };
    using Result = vector<vector<string>>;
    using Board = vector<string>;
    
    void dfs(int row, const int n, Board& board, VisitSets& visited, Result& res) {
        if (row >= n) {
            res.push_back(board);
            return;
        }

        for (Index col = 0; col < n; ++col) {
            // if another queen on that spot, skip
            if (visited.diag_nw[nw::diagonal_lookup(row,col, n)] || visited.diag_ne[ne::diagonal_lookup(row,col)] || visited.col_set[col]) {
                continue;
            }
            // add queen
            board[row][col] = 'Q';
            visited.diag_nw[nw::diagonal_lookup(row,col, n)] = 1;
            visited.diag_ne[ne::diagonal_lookup(row,col)] = 1;
            visited.col_set[col] = 1;
            
            dfs(row+1, n, board, visited, res);
            
            // remove queen
            board[row][col] = '.';
            visited.diag_nw[nw::diagonal_lookup(row,col, n)] = 0;
            visited.diag_ne[ne::diagonal_lookup(row,col)] = 0;
            visited.col_set[col] = 0;
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        VisitSets visited(n);
        Board board(n, string(n,'.'));
        Result res{};
        dfs(0, n, board, visited, res);
        return res;
    }
};
