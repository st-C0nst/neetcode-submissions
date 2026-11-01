#include <print>
class TimeMap {
public:
struct Entry {
    string value;
    int timestamp;
};
using Size = std::size_t;
struct StringHash {
    using is_transparent = void;
    Size operator()(const string& str) const noexcept {
        return std::hash<string>{}(str);
    }

    Size operator()(std::string_view str) const noexcept {
        return std::hash<string_view>{}(str);
    }
    Size operator()(const char* str) const noexcept {
        return std::hash<string_view>{}(str);
    }
};
using History = std::vector<Entry>;
using KVStore = std::unordered_map<string, History, StringHash>;
    public:
    TimeMap() {  } 
    void set(string key, string value, int timestamp) {
        histories_[std::move(key)].emplace_back(std::move(value), timestamp);
    }
    
    string get(string key, int timestamp) {
        if (auto res = histories_.find(key); res != histories_.end()) {
            auto& history = res->second;
            auto upper = std::ranges::upper_bound(history, timestamp, {},&Entry::timestamp);
            if (upper == history.begin()) {
                return "";
            }
            return (upper-1)->value;
        }
        return "";
    }
    private:
     KVStore histories_{};
};

// key1: (value1, 10), 