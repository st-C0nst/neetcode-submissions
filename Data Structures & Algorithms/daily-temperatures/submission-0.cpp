#include <stack>
#include <ranges>

class Solution {
public:
    using TempEntry = std::pair<int, int>;
    using TempStack = std::stack<TempEntry>;
    
    void process_temp(int temp, TempStack& temp_peaks) const {
        while (!temp_peaks.empty() && temp >= temp_peaks.top().first) {
            temp_peaks.pop();
        }
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        TempStack temp_peaks;
        std::vector<int> peak_temp_ranges(temperatures.size());
        for (const auto& [day, temp] : temperatures | std::views::enumerate | std::views::reverse) {
            process_temp(temp, temp_peaks);
            if (temp_peaks.empty()) {
                peak_temp_ranges[day] = 0;
            }
            else {
                peak_temp_ranges[day] = temp_peaks.top().second - day;
            }
            
            temp_peaks.push({temp, day});
        }
        
        return peak_temp_ranges;
    }
};

// for every temp, try to add it to the monotonic stack, use the monotonic ordering to find the distance