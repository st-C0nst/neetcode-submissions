class Solution {
public:
    class TwoPointer {
      public:  
        TwoPointer(const vector<int>& heights) :
        left_boundary{0},
        right_boundary{
            static_cast<int>(heights.size()) - 1
        },
        right_max{heights.back()},
        left_max{heights.front()},
        heights(heights) {}
        
        void shrink() {
            switch (get_shrink_direction()) {
                case ShrinkDirection::Left:
                    shrink_left();
                    break;
                case ShrinkDirection::Right:
                    shrink_right();
                    break;
            }
        }
        inline void shrink_left() {
            ++left_boundary;
            if (!is_valid()) {
                return;
            }
            
            left_max = max(left_max, heights[left_boundary]);
        }

        inline void shrink_right() {
            --right_boundary;

            if (!is_valid()) {
                return;
            }
            right_max = max(right_max, heights[right_boundary]);
        }
        enum class ShrinkDirection {Left, Right};
        [[nodiscard]]
        inline ShrinkDirection get_shrink_direction() const {
            if (get_min_boundary() == left_boundary) {
                return ShrinkDirection::Left;
            }
            else {
                return ShrinkDirection::Right;
            }
        }

        [[nodiscard]]
        inline int get_min_boundary() const {
            if (left_max > right_max) {
                return right_boundary;
            }
            else {
                return left_boundary;
            }
        }
        
        [[nodiscard]]
        int get_container_height() const noexcept {
            return min(left_max, right_max);
        }
        

        bool is_valid() {
            return left_boundary < right_boundary;
        }

        int contained_water() const {
            const auto col = get_min_boundary();
            const auto water_depth = get_container_height() - heights[col];
            return water_depth >= 0 ? water_depth : 0;
        }
        
        int step_water() {
            int water = contained_water();
            shrink();
            return water;
        }
        
        int left_boundary;
        int right_boundary;
        
      private:
        int left_max;
        int right_max;
        std::span<const int> heights;
    };
    
    
    int trap(vector<int>& height) {
        TwoPointer bounds(height);
        int total_water = 0;
        while (bounds.is_valid()) {
            total_water += bounds.step_water();
        }
        return total_water;
    }
};