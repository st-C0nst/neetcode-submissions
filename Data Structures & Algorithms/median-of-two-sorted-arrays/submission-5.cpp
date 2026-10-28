#include <limits>
constexpr auto inf = numeric_limits<int>::max();
constexpr auto ninf = numeric_limits<int>::min();

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const auto total = nums1.size() + nums2.size();
        const auto half = total/2;
        std::span<const int> a{nums1};
        std::span<const int> b{nums2};
        
        if (b.size() < a.size()) {
            std::swap(a,b);
        }
        
        int l = 0;
        int r = a.size();

        while (l <= r) {
            int l1 = (r - l)/2 + l;
            int l2 = half - l1;

            int al = l1 == 0 ? ninf : a[l1-1];
            int bl = l2 == 0 ? ninf : b[l2-1];
            int ar = l1 >= a.size() ? inf : a[l1];
            int br = l2 >= b.size() ? inf : b[l2];

            if (al <= br && bl <= ar) {
                // even
                if (total % 2 == 0) {
                    return (max(al, bl) + min(ar, br)) / 2.0;
                }
                return min(ar,br);
                
            }
            else if (al > br) {
                r = l1 - 1;
            }
            else {
                l = l1 + 1;
            }
        }
        return -1;
    }
};

// to make it cleaner just say out of bounds is inf