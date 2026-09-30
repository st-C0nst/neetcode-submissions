#include <stack>
#include <utility>

class Solution {
public:
    using CalcStack = std::stack<int>;
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

    std::optional<int> num(string_view str) const {
        int num{};
        auto [_, ec] = from_chars(str.data(), str.data() + str.size(), num);
        if (ec == std::errc{}) {
            return num;
        }
        else {
            return {};
        }
    }

    // assume the str is an actual operand
    inline char operand(string_view str) const {
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
        std::unreachable();
    }
    
    void calculate(CalcStack& calc_stack, const vector<string>& tokens) const {
        for (const auto& t : tokens) {
            if (auto n = num(t); n.has_value()) {
                calc_stack.push(n.value());
            }
            else {
                auto b = calc_stack.top(); calc_stack.pop();
                auto a = calc_stack.top(); calc_stack.pop();
                auto res = eval_operand(a, b, operand(t));
                calc_stack.push(res);
            }
        }
    }
    int evalRPN(vector<string>& tokens) {
        CalcStack calc_stack;
        calculate(calc_stack, tokens);

        return calc_stack.top();
    }
};
