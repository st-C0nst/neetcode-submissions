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
            if (left_max > right_max) {
                shrink_right();
            }
            else {
                shrink_left();
            }
        }
        
        bool is_valid() {
            return left_boundary < right_boundary;
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
        
        int contained_water() const {
            const auto col = left_max > right_max ? right_boundary : left_boundary;
            const auto water_depth = min(left_max, right_max) - heights[col];
            return water_depth >= 0 ? water_depth : 0;
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