using Pos = std::pair<int,int>;
constexpr std::array<Pos, 4> directions  {{
    {1,0}, // up
    {0,1}, // right
    {-1,0}, // down
    {0,-1}, // left
}};

class Solution {
public:
    using Board = vector<vector<char>>;
    static bool valid_position(const Pos pos, const Board& board) {
        const int total_rows = board.size();
        const int total_cols = board[0].size();
        auto [row, col] = pos;
        return row >=0 && row < board.size() && col >= 0 && col < board[0].size();
    }
    static bool dfs(Board& board, const Pos position, string_view word) {
        if (word.empty()) return true;
        auto [row, col] = position;
        if (board[row][col] != word.front()) return false;
        else if (word.size() == 1) { return true; }

        // mark as visited
        const auto letter = board[row][col];
        board[row][col] = '#';
        

        for (const auto [dr, dc] : directions) {
            const auto new_row = row + dr;
            const auto new_col = col + dc;
            
            if (!valid_position({new_row, new_col}, board)) {
                continue;
            }
            
            auto found_word = dfs(board, {new_row, new_col}, word.substr(1));
            
            if (found_word) {
                return true;
            }
            
        }
        board[row][col] = letter;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int row = 0; row < board.size(); ++row) {
            for (int col = 0; col < board[0].size(); ++col) {
                if (dfs(board, {row, col}, word)) return true;
            }
        }
        return false;
    }
};
