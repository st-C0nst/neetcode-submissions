#include <vector>
class Solution {
public:
    vector<int> create_prefix_product(const vector<int>& nums) const {
        vector<int> prefix_product(nums.size());
        prefix_product[0] = 1;

        for (int i = 0; i < nums.size() - 1; ++i) {
            prefix_product[i + 1] = prefix_product[i] * nums[i];
        }
        return prefix_product;
    }

    vector<int> create_postfix_product(const vector<int>& nums) const {
        vector<int> postfix_product(nums.size());

        postfix_product.back() = 1;

        for (int i = nums.size() - 1; i > 0; --i) {
            postfix_product[i - 1] = postfix_product[i] * nums[i];
        }
        return postfix_product;
    }
    
    vector<int> productExceptSelf(vector<int>& nums) {
        auto prefix = create_prefix_product(nums);
        auto postfix = create_postfix_product(nums);

        vector<int> product_except_self(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            product_except_self[i] = postfix[i] * prefix[i];
        }
        return product_except_self;
    }
};
