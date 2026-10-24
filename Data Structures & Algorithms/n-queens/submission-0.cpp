#include <print>
using Index = int;
namespace nw {
bool in_bottom_left(Index row, Index col) {
    return col > row;
}
Index diag_bl_index(Index row, Index col, const int n) {
    return n + row - 1 - col;
}
Index diag_tr_index(Index row, Index col, const int n) {
    return n - col - 1 + row;
}
Index diagonal_lookup(Index row, Index col, const int n) {
    return in_bottom_left(row, col) ? diag_bl_index(row, col, n) : diag_tr_index(row, col, n);
}
};


namespace ne {
Index diagonal_lookup(Index row, Index col) {
    return row + col;
}
};
class Solution {
public:
    using Bool = std::uint8_t;
    struct VisitSets {
        VisitSets(int n) : col_set(n), row_set(n), diag_set_nw(n + n -1),diag_set_ne(n*2 + 1), size{n}{}
        std::vector<Bool> col_set;
        std::vector<Bool> row_set;

        Bool& diag_nw(Index row, Index col) {
            return diag_set_nw[nw::diagonal_lookup(row, col, size)];
        }
        Bool& diag_ne(Index row, Index col) {
            
            return diag_set_ne[ne::diagonal_lookup(row, col)];
        }
        
        private:
            std::vector<Bool> diag_set_nw;
            std::vector<Bool> diag_set_ne;
            int size;
    };
    using Candidate = vector<string>;
    using Result = vector<vector<string>>;
    
    void dfs(const int n, Candidate& candidate, VisitSets& visited, Result& res) {
        // std::println("dfs candidate size {}", candidate.size());
        if (candidate.size() >= n) {
            // std::println("found a result");
            res.push_back(candidate);
            return;
        }

        Index row = candidate.size();
        candidate.push_back(string(n, '.'));
        // std::println("enter loop");
        for (Index col = 0; col < n; ++col) {
            // if another queen on that spot, skip
            // std::println("col in loop {}", col);
            if (visited.diag_nw(row, col) == 1 || visited.diag_ne(row,col) == 1 || visited.col_set[col] == 1 || visited.row_set[row] == 1) {
                // std::println("skipping row {} col {}", row, col);
                continue;
            }
            // std::println("add a queen");
            // add queen
            candidate[row][col] = 'Q';
            visited.diag_nw(row, col) = 1;
            visited.diag_ne(row, col) = 1;
            visited.row_set[row] = 1;
            visited.col_set[col] = 1;
            
            dfs(n, candidate, visited, res);
            
            // remove queen
            candidate[row][col] = '.';
            visited.diag_nw(row, col) = 0;
            visited.diag_ne(row, col) = 0;
            visited.row_set[row] = 0;
            visited.col_set[col] = 0;
        }
        // remove the row
        candidate.pop_back();
    }
    
    vector<vector<string>> solveNQueens(int n) {
        VisitSets visited(n);
        Result res{};
        Candidate c{};
        c.reserve(n);
        dfs(n, c, visited, res);
        return res;
    }
};
