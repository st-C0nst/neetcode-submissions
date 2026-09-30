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

    int temp_distance(int day,const TempStack& temp_peaks) const {
        if (temp_peaks.empty()) {
            return 0;
        }
        else {
            return temp_peaks.top().second - day;
        }
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        TempStack temp_peaks;
        std::vector<int> peak_temp_ranges(temperatures.size());
        for (const auto& [day, temp] : temperatures | std::views::enumerate | std::views::reverse) {
            process_temp(temp, temp_peaks);
            peak_temp_ranges[day] = temp_distance(day, temp_peaks);
            temp_peaks.push({temp, day});
        }
        
        return peak_temp_ranges;
    }
};

// for every temp, try to add it to the monotonic stack, use the monotonic ordering to find the distance