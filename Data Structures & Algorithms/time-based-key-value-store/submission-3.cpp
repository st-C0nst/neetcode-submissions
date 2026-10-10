#include <ranges>

class TimeMap {
public:
    class TimestampEntry {
        public:
            TimestampEntry(int timestamp, string key, string value) noexcept : timestamp{timestamp}, key_(std::move(key)), value_(std::move(value)) { }
            
            string_view get_value() const {
                return value_;
            }
            const int timestamp{};
            
        private:
            const string key_;
            const string value_;
    };
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        time_kv_map[key].emplace_back(timestamp, std::move(key), std::move(value));
    }
    
    std::span<const TimestampEntry> key_matches(const string& key) const {
        if (auto it = time_kv_map.find(key); it != time_kv_map.end()) {
            return std::span<const TimestampEntry>{it->second};
        }
        return std::span<const TimestampEntry>{};
    }
    
    string get(string key, int timestamp) {
        auto matches = key_matches(key);
        
        
        auto it = std::ranges::upper_bound(matches, timestamp, std::ranges::less{}, &TimestampEntry::timestamp);
        
        if (it == matches.begin()) {
            return "";
        }
        --it;
        return string(it->get_value());
    }
private:
    using HistoricValues = std::vector<TimestampEntry>;
    unordered_map<string, HistoricValues> time_kv_map;
};

