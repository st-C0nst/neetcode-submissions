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
    // head tail and size of range
    using Size = std::size_t;
    struct ListRange {
      ListNode* head = nullptr;  
      ListNode* tail = nullptr;
      Size size{};
    };
    
    // detach and return the next value in list
    std::optional<ListRange> sublist(ListNode* start, const int size){
        if (!start) return {};

        ListRange range{};

        auto curr = start;
        while (curr && range.size < size) {
            if (range.head == nullptr || range.tail == nullptr) {
                range.head = curr;
                range.tail = curr;
            }
            ++range.size;
            range.tail = curr;
            curr = curr->next;
        }
        
        if (range.size == size) {
            return range;
        }
        return {};
    }
    
    // create the list of ranges and then return remainder if there is one
    std::pair<std::vector<ListRange>, ListNode*> create_ranges(ListNode* head, const int range_size) {
        auto curr = head;
        std::vector<ListRange> sub_ranges;
        ListNode* remainder = nullptr;
        while (curr) {
            // create the next range
            auto range = sublist(curr, range_size);
            if (range) {
                sub_ranges.push_back(*range);
                // step head past the range
                curr = range->tail->next;
            }
            // if we couldnt create it but head is not null then we have remainder
            else {
                remainder = curr;
                // step head to end
                curr = nullptr;
            }
        }
        return {sub_ranges, remainder};
    }
    ListNode* reverse_list(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    // void print_list(ListNode* head, ListNode* end) {
    //     auto curr = head;
    //     while (curr && curr != end) {
    //         std::print("{}, ", curr->val);
    //         curr = curr->next;
    //     }
    //     std::println("");
    // }
    
    void detatch_range(ListRange& range) {
        range.tail->next = nullptr;
    }

    static ListRange join_ranges(ListRange r1, ListRange r2) {
        r1.tail->next = r2.head;
        return {r1.head, r2.tail, r1.size + r2.size};
    }
    // assumes range is seperated
    void reverse_range(ListRange& range) {
        
        auto new_tail = range.head;
        auto new_head = reverse_list(range.head);

        range.head = new_head;
        range.tail = new_tail;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto [ranges, remainder] = create_ranges(head, k);
        for (auto& range : ranges) {
            detatch_range(range);
            reverse_range(range);
        }
        auto joined = std::ranges::fold_left_first(ranges, join_ranges);
        if (!joined) return remainder;
        joined->tail->next = remainder;
        return joined->head;
    }
};
