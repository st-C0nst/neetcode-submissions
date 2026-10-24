#include <queue>
#include <ranges>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    using Index = std::size_t;
    // sort on value, index to get next head
    using Iterator = ListNode*;
    using HeapEntry = std::tuple<int, Iterator>;
    using MinHeap = std::priority_queue<HeapEntry, std::vector<HeapEntry>, std::greater<>>;
    static std::optional<ListNode*> next(Iterator& iterator) {
        // if empty do nothing
        if (iterator == nullptr) return {};

        iterator = iterator->next;
        if (iterator == nullptr) return {};
        return iterator;
    }
    
    static MinHeap init_heap(std::span<ListNode*> lists) {
        std::vector<HeapEntry> heads;
        heads.reserve(lists.size());
        for (auto l : lists) {
            if (auto head = l; head != nullptr) {
                heads.push_back({head->val, head});
            }
        }
        return MinHeap({}, std::move(heads));
    }
    ListNode* pop(MinHeap& min_heads) {
        auto [_, node] = min_heads.top();
        auto l = node;
        min_heads.pop();
        
        if (auto next_node = next(l); next_node) {
            min_heads.push({(*next_node)->val, *next_node});
        }
        node->next = nullptr;
        
        return node;
    }
    
    void push_back(ListNode*& head, ListNode*& tail, ListNode* node) {
        if (head == nullptr && tail == nullptr)  {
            head = node;
            tail = node;
            return;
        }
        tail->next = node;
        tail = node;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto min_heads = init_heap(lists);
        
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        while (!min_heads.empty()) {
            // get curr head
            auto min_node = pop(min_heads);
            push_back(head, tail, min_node);
        }
        return head;
    }
};

// we already store the head so we dont need to operate on the list

// we dont even need to modify the lists, the node can just iterate over them