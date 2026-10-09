class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.front() < nums.back()) return nums[0];
        
        int l = 0;
        int r = nums.size() - 1;
        
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < nums[0]) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return nums[l];
    }
};
