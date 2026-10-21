class Solution {
public:
    static constexpr char lower = 'a';
    std::array<std::int16_t, 26> counts{};
    std::int16_t& get_count(unsigned char c) {
        return counts[c - lower];
    }
    
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) {
            return false;
        }
        int num_diff = 0;
        int r = 0;
        for (; r < s1.size(); ++r) {
            if (get_count(s1[r])++ == 0) {
                ++num_diff;
            }
        }
        if (num_diff == 0) return true;

        int l = 0;
        for (int r = 0; r < s2.size(); ++r) {
            // add r
            auto prev_count = get_count(s2[r])--;
            if (prev_count == 0) {
                ++num_diff;
            }
            else if (get_count(s2[r]) == 0) {
                --num_diff;
            }
            
            // if window too large shrink
            if (r - l + 1 > s1.size()) {
                auto prev_l_count = get_count(s2[l])++;
                if (prev_l_count == 0) {
                    ++num_diff;
                }
                else if (get_count(s2[l]) == 0) {
                    --num_diff;
                }
                ++l;
            }


            if (num_diff == 0) {
                return true;
            }
        }
        return false;
    }
};

// count num mismatches
// go through s1 count the number of characters
// go through s2, decrement the count. if a count ever hits 0, then we know the num diff chars has changed
// track num diff chars (non zero counts)
// what about negatives?
// if all counts are 0 then the window is valid
// counting up or down from 0 will increment the non matching count

// a b c
// l e c a b e e

// if it was 0 and we changed it, then we should modify non matching
// non matching = 0
// counts {
//    a = 0
//    b = 0
//    c = 0
//    l = 0
//    e = 0
// }

// fixed window len problem
// grow r until its of the fixed size
// then slide the window

// edge cases: if s2 < s1 early exit

// remove l means to add the count
// add r means to decrease the count
// whether we add or remove we should update the non matching
// we should start with window being valid then slide 
// or just process the first window outside then slide then process at end of the loop