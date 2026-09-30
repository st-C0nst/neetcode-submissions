#include <stack>
#include <utility>

class Solution {
public:
    using CalcStack = std::stack<std::string>;
    int eval_operand(int a, int b, char op) const {
        switch (op) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                return a / b;
        }
        std::unreachable();
    }

    // optimization, only call num if we know it can succeed
    int num(string_view str) const {
        int num{};
        from_chars(str.data(), str.data() + str.size(), num);
        return num;
    }

    inline std::optional<char> operand(string_view str) const {
        if (str.size() > 1) return {};
        switch (str[0]) {
            case '*':
                return '*';
            case '+':
                return '+';
            case '/':
                return '/';
            case '-':
                return '-';
        }
        return {};
    }
    
    void calculate(CalcStack& calc_stack, const vector<string>& tokens) const {
        for (const auto& t : tokens) {
            if (auto op = operand(t); op.has_value()) {
                auto b = calc_stack.top(); calc_stack.pop();
                auto a = calc_stack.top(); calc_stack.pop();
                auto res = eval_operand(num(a), num(b), op.value());
                calc_stack.push(std::to_string(res));
            }
            else {
                calc_stack.push(t);
            }
        }
    }
    int evalRPN(vector<string>& tokens) {
        CalcStack calc_stack;
        calculate(calc_stack, tokens);

        return num(calc_stack.top());
    }
};
