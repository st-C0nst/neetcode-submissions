class Solution {
public:
    using Count = std::uint8_t;
    struct CandidateParentheses {
        string candidate;
        Count num_open{};
        Count num_close{};

        CandidateParentheses(Count num_parentheses) : n_{num_parentheses} {
            candidate.reserve(num_parentheses * 2);
        }
        
        void open() {
            if (!can_open()) return;
            candidate.push_back('(');
            ++num_open;
        }
        void close() {
            if (!can_close()) return;
            candidate.push_back(')');
            ++num_close;
        }
        
        void remove() {
            // assume its only called on non empty string
            const unsigned char bracket = candidate.back();
            candidate.pop_back();
            switch (bracket) {
                case '(':
                    --num_open;
                    break;
                case ')':
                    --num_close;
                    break;
            }
        }
        
        [[nodiscard]]
        bool can_open() const {
            return num_open < n_;
        }
        
        [[nodiscard]]
        bool can_close() const {
            return num_open > num_close;
        }

        [[nodiscard]]
        bool is_valid() const {
            return candidate.size() == n_ * 2;
        }
        private:
            Count n_;
    };
    using Results = std::vector<string>;
    static void dfs(CandidateParentheses& candidate, Results& results) {
        if (candidate.is_valid()) {
            results.push_back(candidate.candidate);
        }

        if (candidate.can_open()) {
            candidate.open();
            dfs(candidate, results);
            candidate.remove();
        }
        if (candidate.can_close()) {
            candidate.close();
            dfs(candidate, results);
            candidate.remove();
        }
    }
    vector<string> generateParenthesis(int n) {
        CandidateParentheses candidate(static_cast<std::uint8_t>(n));
        Results results;

        dfs(candidate, results);
        return results;
    }
};
