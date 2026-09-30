#include <stack>
#include <utility>

class MinStack {
public:
    using StackContainer = std::stack<std::pair<int,int>>;
    
    MinStack() {
        
    }
    
    void push(int val) {
        if (container_.empty()) {
            container_.push({val, val});
            return;
        }

        auto curr_min = container_.top().second;
        container_.push({val, min(val, curr_min)});
    }
    
    // assume we dont pop when empty
    void pop() {
        container_.pop();
    }
    
    int top() {
        return container_.top().first;
    }
    
    int getMin() {
        return container_.top().second;
    }
    private:
        StackContainer container_;
};
