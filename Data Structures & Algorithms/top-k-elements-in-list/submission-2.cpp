#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <ranges>

class Solution {
public:
    // freq, num pair
    using HeapEntry = std::pair<int, int>;

    template <typename EntryType, typename Container = std::vector<EntryType>, typename Comparator = std::less<EntryType>>
    class TransparentHeap : public std::priority_queue<EntryType, Container, Comparator> {
    public:
        using Base = std::priority_queue<EntryType, Container, Comparator>;
        using Base::Base;
        
        const Container& get_underlying() const {
            return this->c;
        }
    };
    
    unordered_map<int, int> make_frequency_map(const vector<int>& nums) const {
        unordered_map<int, int> freq_by_num;
        for (const auto& n : nums) {
            ++freq_by_num[n];
        }
        return freq_by_num;
    }
    using MinHeap = TransparentHeap<HeapEntry, std::vector<HeapEntry>, std::greater<HeapEntry>>;
    
    // side effect of modifying the heap passed in
    void find_top_k(const int k, MinHeap& top_k_heap, const unordered_map<int,int>& freq_by_num) const {
        for (const auto& [num, freq] : freq_by_num) {
            if (top_k_heap.size() < k) {
                top_k_heap.push({freq, num});
            }
            else if (freq > top_k_heap.top().first) {
                top_k_heap.pop();
                top_k_heap.push({freq, num});
            }
        }
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<HeapEntry> underlying;
        underlying.reserve(k);
        MinHeap top_k_heap{std::greater<HeapEntry>{}, std::move(underlying)};
        
        auto freq_by_num = make_frequency_map(nums);
        find_top_k(k, top_k_heap, freq_by_num);

        return top_k_heap.get_underlying() | std::views::values | std::ranges::to<vector>();
    }
};
