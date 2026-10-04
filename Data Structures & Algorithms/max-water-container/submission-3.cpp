class Solution {
public:
    using TwoPointer = std::pair<int, int>;
    
    inline void shrink_left(TwoPointer& ptrs, const vector<int>& heights) const {
        auto& [left, right] = ptrs;
        const int threshhold = heights[left];
        
        ++left;
        while (left < right && heights[left] < threshhold) {
            ++left;
        }
    }
    inline void shrink_right(TwoPointer& ptrs, const vector<int>& heights) const {
        auto& [left, right] = ptrs;
        const int threshhold = heights[right];
        
        --right;
        while (left < right && heights[right] < threshhold) {
            --right;
        }
    }

    enum class Direction { Left, Right, Both};
    [[nodiscard]]
    inline Direction find_shrink_direction(const TwoPointer ptrs, const vector<int>& heights) const {
        const auto [left, right] = ptrs;
        if (heights[left] == heights[right]) {
            return Direction::Both;
        }
        else if (heights[left] > heights[right]) {
            return Direction::Right;
        }
        else {
            return Direction::Left;
        }
        
    }
    
    [[nodiscard]]
    inline int calc_area(const TwoPointer ptrs, const vector<int>& heights) const {
        const auto [left, right] = ptrs;
        const int length = right - left;
        return length * min(heights[left], heights[right]);
    }
    
    int handle_tie(TwoPointer ptrs, const vector<int>& heights) const {
        return max(find_max_area({ptrs.first + 1, ptrs.second}, heights), 
                    find_max_area({ptrs.first, ptrs.second - 1}, heights));
    }
    
    [[nodiscard]]
    int find_max_area(TwoPointer ptrs, const vector<int>& heights) const {
        if (ptrs.first >= ptrs.second) return 0;
        int max_area = 0;
        
        while (ptrs.first < ptrs.second) {
            max_area = max(max_area, calc_area(ptrs, heights));
            
            switch (find_shrink_direction(ptrs, heights)) {
                case Direction::Both:
                    return max(max_area, handle_tie(ptrs, heights));
                case Direction::Left:
                    shrink_left(ptrs, heights);
                    break;
                case Direction::Right:
                    shrink_right(ptrs, heights);
                    break;
            }
        }
        return max_area;
    }
    
    int maxArea(vector<int>& heights) {
        TwoPointer ptrs{0, heights.size() - 1};
        return find_max_area(ptrs, heights);
    }
};
