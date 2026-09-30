#include <stack>
#include <ranges>

class Solution {
public:
    [[nodiscard]]
    float travel_time(int velocity, int distance) const {
        return static_cast<float>(distance) / static_cast<float>(velocity);
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::stack<float> arrival_times;
        auto zipped = std::views::zip(position, speed);
        std::ranges::sort(zipped);

        for (const auto& [pos, speed] : zipped) {
            auto dt = travel_time(speed, target-pos);
            while (!arrival_times.empty() && dt >= arrival_times.top()){
                arrival_times.pop();
            }
            
            arrival_times.push(dt);
        }
        return arrival_times.size();
    }
};