#include <array>

constexpr std::array<std::pair<int,int>, 4> dirs{{
    {1,0},
    {0,1},
    {-1, 0},
    {0, -1}
}};

class Solution {
public:
using Board = vector<vector<char>>;
    static bool in_bounds(int row, int col, const Board& board) {
        if (row < 0 || row >= board.size()) return false;
        if (col < 0 || col >= board[0].size()) return false;
        return true;
    }
    static void is_surrounded(int row, int col,Board& board) {
        // not surrounded
        if (!in_bounds(row,col,board)) {
            return;
        }
        
        // not valid but not an edge
        if (board[row][col] != 'O') {
            return;
        }

        // mark visited
        board[row][col] = 'T';
        for (const auto [drow, dcol] : dirs) {
            const auto n_row = row + drow;
            const auto n_col = col + dcol;

            is_surrounded(n_row, n_col, board);
        }

    }
    void solve(vector<vector<char>>& board) {
        
        for (int row = 0; row < board.size(); ++row) {
            is_surrounded(row, 0,board);
            is_surrounded(row, board[0].size() - 1,board);
        }
        for (int col = 1; col < board[0].size() - 1; ++col) {
            is_surrounded(0, col,board);
            is_surrounded(board.size() - 1, col,board);
        }
        for (int row = 0; row < board.size(); ++row) {
            for (int col = 0; col < board[0].size(); ++col) {
                if (board[row][col] == 'O') {
                    board[row][col] = 'X';
                }
                else if (board[row][col] == 'T') {
                    board[row][col]= 'O';
                }
            }
        }
        
    }
};

// not surrounded if we hit an edge, thus dfs and track if we hit an edge, mark as visited as well ig
// can I just mark it as X? 
// we can do a two pass solution where we first mark as visited then go through again. reason we might want to do this is 
// if the current cell is actually searched and we find its edge piece then we want to revert
