#include <optional>
#include <stack>

class Solution {
public:
    std::optional<char> handle_closing_brace(char c) const {
        switch (c) {
            case '}':
                return '{';
            case ')':
                return '(';
            case ']':
                return '[';
            default:
                return {};
        }
    }
    bool process_braces(string_view s) const {
        stack<char> braces;
        for (const auto& c : s) {
            if (auto open_brace = handle_closing_brace(c); open_brace.has_value()) {
                if (braces.empty() || braces.top() != open_brace.value()) {
                    return false;
                }
                braces.pop();
            }
            else {
                braces.push(c);
            }
        }
        return braces.empty();
    }
    
    bool isValid(string s) {
        if (s.empty()) return true;

        return process_braces(s);
    }
};
