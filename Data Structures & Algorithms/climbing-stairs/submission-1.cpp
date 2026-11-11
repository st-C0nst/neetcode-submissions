class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        auto step_1{2};
        auto step_2{1};
        
        for (int i = n - 2; i > 0; --i) {
            auto curr = step_1 + step_2;
            step_2 = step_1;
            step_1 = curr;
        }
        return step_1;
    }
};


// start at 1, climb until we hit n+1 step
// subproblem: given we are at step i, what are the number of ways to reach step n+1
// base case: if we are at step n, there is exactly 1 way to reach end.
// choose: choose to step by 2 or by 1
// state: number of steps to reach the top
// num_paths[i] = min_steps[i+1] + min_steps[i + 2]

// space optimization, only need next two in answer
// start at first 2 n and n -1. num ways for n is 1, num ways for n - 1 is 2
