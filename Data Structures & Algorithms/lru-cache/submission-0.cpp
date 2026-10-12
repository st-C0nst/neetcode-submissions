#include <unordered_map>
#include <list>

class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity) { }
    
    int get(int key) {
        if (auto entry = lookup_.find(key); entry != lookup_.end()) {
            touch_entry(entry->second);
            return entry->second->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (auto entry = lookup_.find(key); entry != lookup_.end()) {
            touch_entry(entry->second);
            entry->second->second = value;
        }
        else {
            lru_.push_front({key, value});
            lookup_[key] = lru_.begin();
        }

        shrink_to_capacity();
    }
private:
    using LruEntry = std::pair<int,int>;
    using LruList = list<LruEntry>;
    using ListPtr = LruList::iterator;
    using LruMap = unordered_map<int, ListPtr>;
    const int capacity_;
    LruMap lookup_;
    LruList lru_;

    void touch_entry(ListPtr ptr) {
        lru_.splice(lru_.begin(), lru_, ptr);
    }

    void shrink_to_capacity() {
        if (lru_.size() > capacity_) {
            lookup_.erase(lru_.back().first);
            lru_.pop_back();
        }
    }
};
