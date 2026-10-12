class Solution {
public:
    
    static std::size_t find_duplicate(std::span<const int> nums) {
        std::size_t slow = 0;
        std::size_t fast = 0;

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (fast != slow);

        slow = 0;
        
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
    
    int findDuplicate(vector<int>& nums) {
        if (nums.size() <= 2) return nums[0];
        
        return find_duplicate(nums);
    }
};
