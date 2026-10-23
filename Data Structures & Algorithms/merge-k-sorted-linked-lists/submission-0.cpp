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
    using HeapEntry = std::tuple<int, ListNode*,Index>;
    using MinHeap = std::priority_queue<HeapEntry, std::vector<HeapEntry>, std::greater<>>;
    static std::optional<ListNode*> pop_front(ListNode*& l) {
        // if empty do nothing
        if (l == nullptr) return {};

        auto node = l;
        l = l->next;
        return node;
    }
    
    static MinHeap init_heap(std::span<ListNode*> lists) {
        std::vector<HeapEntry> heads;
        heads.reserve(lists.size());
        for (auto [l_idx, l] : lists | std::views::enumerate) {
            if (auto head = pop_front(l); head) {
                heads.push_back({(*head)->val, *head, l_idx});
            }
        }
        return MinHeap({}, std::move(heads));
    }
    ListNode* pop(MinHeap& min_heads,std::span<ListNode*> lists) {
        auto [val, node, list_idx] = min_heads.top();
        min_heads.pop();
        
        if (auto new_head = pop_front(lists[list_idx]); new_head) {
            min_heads.push({(*new_head)->val, *new_head, list_idx});
        }
        
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
            auto min_node = pop(min_heads, lists);
            push_back(head, tail, min_node);
        }
        return head;
    }
};

