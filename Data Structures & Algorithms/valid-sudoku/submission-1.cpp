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

        static SudokuCounter from_box(const Grid& board, int box_row, int box_col) {
            SudokuCounter counts;
            const int upper_row = box_row * 3 + 3;
            const int upper_col = box_col * 3 + 3;
            for (int row = box_row * 3; row < upper_row; ++row) {
                for (int col = box_col * 3; col < upper_col; ++col) {
                    const char num = board[row][col];
                    if (num == '.') continue;
                    if (counts[num]++ != 0) {
                        counts.is_valid = false;
                        return counts;
                    }
                }
            }
            return counts;
        }

        static SudokuCounter from_row(const vector<char>& row) {
            SudokuCounter counts;
            for (const auto& c : row) {
                if (c == '.') continue;
                if (counts[c]++ != 0) {
                    // Early exit if invalid
                    counts.is_valid = false;
                    return counts;
                }
            }
            return counts;
        }
        static SudokuCounter from_col(const Grid& board, int col) {
            SudokuCounter counts;
            for (int row = 0; row < 9; ++row) {
                const char num = board[row][col];
                if (num == '.') continue;
                if (counts[num]++ != 0) {
                    counts.is_valid = false;
                    return counts;
                }
            }
            return counts;
        }


        bool is_valid = true;
        private:
            Container counts{};
    };
    bool validate_grids(const Grid& board) {
        for (int grid_row = 0; grid_row < 3; ++grid_row) {
            for (int grid_col = 0; grid_col < 3; ++grid_col) {
                if (!SudokuCounter::from_box(board, grid_row, grid_col).is_valid) {
                    return false;
                }
            }
        }
        return true;
    }

    bool validate_rows(const Grid& board) {
        for (int i = 0; i < 9; ++i) {
            if (!SudokuCounter::from_row(board[i]).is_valid) {
                return false;
            }
        }
        return true;
    }

    bool validate_cols(const Grid& board) {
        for (int i = 0; i < 9; ++i) {
            if (!SudokuCounter::from_col(board, i).is_valid) {
                return false;
            }
        }
        return true;
    }
    
    bool isValidSudoku(Grid& board) {
        return validate_grids(board) && validate_rows(board) && validate_cols(board);
    }
};
