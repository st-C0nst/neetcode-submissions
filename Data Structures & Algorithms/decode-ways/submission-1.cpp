#include <print>
class Solution {
public:
    static bool valid_single(int i, std::string_view str) {
        return (str[i] != '0');
    }
    static bool valid_double(int i, std::string_view str) {
        if (i + 1 >= str.size()) return false;
        if (str[i] == '1') {
            return true;
        }
        if (str[i] == '2') {
            return (str[i+1] >= '0' && str[i+1] <= '6');
        }
        return false;
    }
    int numDecodings(string s) {
        int num_ways1 = 1;
        int num_ways2 = 1;

        for (int i{static_cast<int>(s.size()) -1}; i >= 0; --i) {
            std::size_t curr{0};
            if (valid_single(i, s)) {
                curr += num_ways2;
            }
            if (valid_double(i, s)) {
                curr += num_ways1;
            }

            num_ways1 = num_ways2;
            num_ways2 = curr;
        }
        return num_ways2;
        
    }
};


// subproblem: from i to end what are num ways to decodde
// base case: 0 ways to decode outside of range
// recurrence: num_ways[i] = if is_valid(i, i+1): 1 + num_ways[i + 2] +
// if is_valid(i,i): 1 + num_ways[i+1]

// valid condition for size 1
// any digit besides 1

// valid condition for size 2
// first index is 1 to 2, second index is anything
// space saving, only need to store the prev 2, num ways + 2 and num ways + 1