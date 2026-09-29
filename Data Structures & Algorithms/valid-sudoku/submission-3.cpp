class Solution {
public:
    using Row = vector<char>;
    using Grid = vector<Row>;
    class SudokuCounter {
        public:
        using Container = std::array<int, 9>;
        
        int& operator[](char num) {
            return counts[num - '1'];
        }

        bool add(char digit) {
            if (digit == '.') return true;

            if (counts[digit - '1']++ != 0) {
                return false;
            }
            return true;
        }

        private:
            Container counts{};
    };
    bool validate_col(const Grid& board, int col) {
        SudokuCounter counts;
        for (int row = 0; row < 9; ++row) {
            if (!counts.add(board[row][col])) return false;
        }
        return true;
    }
    bool validate_row(const vector<char>& row) {
        SudokuCounter counts;
        for (const auto& c : row) {
            if (!counts.add(c)) return false;
        }
        return true;
    }
    bool validate_grid(const Grid& board, int box_row, int box_col) {
        SudokuCounter counts;
        const int upper_row = box_row * 3 + 3;
        const int upper_col = box_col * 3 + 3;
        
        for (int row = box_row * 3; row < upper_row; ++row) {
            for (int col = box_col * 3; col < upper_col; ++col) {
                if (!counts.add(board[row][col])) return false;
            }
        }
        return true;
    }
    bool validate_grids(const Grid& board) {
        for (int grid_row = 0; grid_row < 3; ++grid_row) {
            for (int grid_col = 0; grid_col < 3; ++grid_col) {
                if (!validate_grid(board, grid_row, grid_col)) {
                    return false;
                }
            }
        }
        return true;
    }

    bool validate_rows(const Grid& board) {
        for (int i = 0; i < 9; ++i) {
            if (!validate_row(board[i])) {
                return false;
            }
        }
        return true;
    }

    bool validate_cols(const Grid& board) {
        for (int i = 0; i < 9; ++i) {
            if (!validate_col(board, i)) {
                return false;
            }
        }
        return true;
    }
    
    bool isValidSudoku(Grid& board) {
        return validate_grids(board) && validate_rows(board) && validate_cols(board);
    }
};
